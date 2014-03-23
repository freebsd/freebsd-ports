# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	dbmail
PORTVERSION=	3.1.13
CATEGORIES=	mail
MASTER_SITES=	http://www.dbmail.org/download/3.1/ \
		http://git.dbmail.eu/paul/dbmail/snapshot/

MAINTAINER=	ahicks@p-o.co.uk
COMMENT=	SQL database-based mail system (POP3 and IMAP)

LICENSE=	GPLv2

LIB_DEPENDS=	libgmime-2.6.so:${PORTSDIR}/mail/gmime26 \
		libzdb.so:${PORTSDIR}/databases/libzdb \
		libmhash.so:${PORTSDIR}/security/mhash \
		libevent-2.0.so:${PORTSDIR}/devel/libevent2

BUILD_DEPENDS=	asciidoc:${PORTSDIR}/textproc/asciidoc \
		xmlto:${PORTSDIR}/textproc/xmlto \
		${LOCALBASE}/share/sgml/docbook/4.5:${PORTSDIR}/textproc/docbook-sgml

CONFLICTS=	dbmail-2.* dbmail22-[0-9]*

OPTIONS_DEFINE=	DOCS LDAP SIEVE THREADS
OPTIONS_DEFAULT=	THREADS
SIEVE_DESC=	Sieve mail sorting language support

OPTIONS_SUB=	yes

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

SIEVE_CONFIGURE_WITH=	sieve
SIEVE_LIB_DEPENDS=	libsieve.so:${PORTSDIR}/mail/libsieve

LDAP_CONFIGURE_WITH=	ldap
LDAP_USE=		OPENLDAP=yes

THREADS_EXTRA_PATCHES=	${FILESDIR}/extra-patch-acinclude.m4

DBMAIL_USER?=	mailnull
DBMAIL_GROUP?=	mail
PIDDIR?=	/var/run/dbmail

PLIST_SUB+=	DBMAIL_USER="${DBMAIL_USER}" \
		DBMAIL_GROUP="${DBMAIL_GROUP}" \
		PIDDIR="${PIDDIR}"

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
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/dbmail/libauth_sql.so.0 \
		${STAGEDIR}${PREFIX}/lib/dbmail/libdbmail.so.0

.include <bsd.port.mk>
