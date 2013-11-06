# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	dbmail
PORTVERSION=	3.1.7
CATEGORIES=	mail
MASTER_SITES=	http://www.dbmail.org/download/3.1/

MAINTAINER=	ahicks@p-o.co.uk
COMMENT=	SQL database-based mail system (POP3 and IMAP)

LICENSE=	GPLv2

LIB_DEPENDS=	libgmime-2.6.so:${PORTSDIR}/mail/gmime26 \
		libzdb.so:${PORTSDIR}/databases/libzdb \
		libmhash.so:${PORTSDIR}/security/mhash \
		libevent-2.0.so:${PORTSDIR}/devel/libevent2

BUILD_DEPENDS+=	asciidoc:${PORTSDIR}/textproc/asciidoc \
		xmlto:${PORTSDIR}/textproc/xmlto \
		${LOCALBASE}/share/sgml/docbook/4.5/docbookx.dtd:${PORTSDIR}/textproc/docbook-450

CONFLICTS=	dbmail-2.* dbmail22-*

OPTIONS_DEFINE=	DOCS LDAP SIEVE THREADS
OPTIONS_DEFAULT=	THREADS
SIEVE_DESC=	Build with support for Sieve mail sorting language

USE_AUTOTOOLS=	libtool autoheader autoconf
USE_LDCONFIG=	${PREFIX}/lib/dbmail
USE_RC_SUBR=	dbmail-pop3d dbmail-lmtpd dbmail-imapd dbmail-timsieved
USE_OPENSSL=	yes
USES=		gmake shebangfix pkgconfig
SHEBANG_FILES=	man/fixsp.pl

CFLAGS+=	-fPIC ${PTHREAD_CFLAGS}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ARGS+=	--with-zdb=${LOCALBASE} --sysconfdir=${LOCALBASE}/etc --enable-manpages

MAKE_ARGS+=	mandir=${MANPREFIX}/man

DOCS=		AUTHORS BUGS INSTALL THANKS UPGRADING

.include <bsd.port.options.mk>

DBMAIL_USER?=	mailnull
DBMAIL_GROUP?=	mail
PIDDIR?=	/var/run/dbmail

PLIST_SUB+=	DBMAIL_USER="${DBMAIL_USER}" \
		DBMAIL_GROUP="${DBMAIL_GROUP}" \
		PIDDIR="${PIDDIR}"

.if ${PORT_OPTIONS:MSIEVE}
CONFIGURE_ARGS+=--with-sieve=${LOCALBASE}
LIB_DEPENDS+=	libsieve.so:${PORTSDIR}/mail/libsieve
PLIST_SUB+=	SIEVE=""
.else
CONFIGURE_ARGS+=--without-sieve
PLIST_SUB+=	SIEVE="@comment "
.endif

.if ${PORT_OPTIONS:MLDAP}
CONFIGURE_ARGS+=--with-ldap=${LOCALBASE}
USE_OPENLDAP=	yes
PLIST_SUB+=	LDAP=""
.else
CONFIGURE_ARGS+=--without-ldap
PLIST_SUB+=	LDAP="@comment "
.endif

.if ${PORT_OPTIONS:MTHREADS}
EXTRA_PATCHES=	${FILESDIR}/extra-patch-acinclude.m4
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/dbmail.conf ${STAGEDIR}${PREFIX}/etc/dbmail.conf-dist
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/dbmail.schema ${STAGEDIR}${DATADIR}
	@for f in mysql oracle postgresql sqlite; do \
		${MKDIR} ${STAGEDIR}${DATADIR}/$$f ; \
		${INSTALL_DATA} ${WRKSRC}/sql/$$f/* ${STAGEDIR}${DATADIR}/$$f; \
	done
	@${MKDIR} ${STAGEDIR}${PIDDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
