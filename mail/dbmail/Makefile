# New ports collection makefile for:	dbmail
# Date created:				07/26/2003
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	dbmail
PORTVERSION=	3.0.2
PORTREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	http://www.dbmail.org/download/3.0/

MAINTAINER=	ahicks@p-o.co.uk
COMMENT=	An SQL database-based mail system (POP3 and IMAP)

LICENSE=	GPLv2

.if !defined(NOPORTDOCS)
BUILD_DEPENDS=	asciidoc:${PORTSDIR}/textproc/asciidoc \
		xmlto:${PORTSDIR}/textproc/xmlto
.endif
LIB_DEPENDS=	gmime-2.4:${PORTSDIR}/mail/gmime24 \
		zdb:${PORTSDIR}/databases/libzdb \
		mhash:${PORTSDIR}/security/mhash \
		event:${PORTSDIR}/devel/libevent

CONFLICTS=	dbmail-*-2.0.* dbmail-2.*

OPTIONS_DEFINE=	LDAP SIEVE THREADS
OPTIONS_DEFAULT=	THREADS
SIEVE_DESC=	"Build with support for Sieve mail sorting language"

.include <bsd.port.options.mk>

USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_LDCONFIG=	${PREFIX}/lib/dbmail
USE_RC_SUBR=	dbmail-pop3d dbmail-lmtpd dbmail-imapd dbmail-timsieved
USE_OPENSSL=	yes

CFLAGS+=	-fPIC ${PTHREAD_CFLAGS}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ARGS+=	--with-zdb=${LOCALBASE} --sysconfdir=${LOCALBASE}/etc
MAKE_ARGS+=	mandir=${MANPREFIX}/man

PORTDOCS=	AUTHORS BUGS INSTALL THANKS UPGRADING
.if !defined(NOPORTDOCS)
MAN1=		dbmail-deliver.1 dbmail.1
MAN5=		dbmail.conf.5
MAN8=		dbmail-export.8 dbmail-httpd.8 dbmail-imapd.8 \
		dbmail-lmtpd.8 dbmail-pop3d.8 dbmail-sievecmd.8 \
		dbmail-timsieved.8 dbmail-users.8 dbmail-util.8
.endif

DBMAIL_USER?=	mailnull
DBMAIL_GROUP?=	mail
PIDDIR?=	/var/run/dbmail

PLIST_SUB+=	DBMAIL_USER="${DBMAIL_USER}" \
		DBMAIL_GROUP="${DBMAIL_GROUP}" \
		PIDDIR="${PIDDIR}"

.if defined(NOPORTDOCS)
PLIST_SUB+=	PORTDOCS="@comment "
.else
PLIST_SUB+=	PORTDOCS=""
.endif

.if ${PORT_OPTIONS:MSIEVE}
CONFIGURE_ARGS+=--with-sieve=${LOCALBASE}
LIB_DEPENDS+=	sieve:${PORTSDIR}/mail/libsieve
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
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-configure
.endif

.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--enable-manpages
.endif

post-install:
	@${INSTALL_DATA} ${WRKSRC}/dbmail.conf ${PREFIX}/etc/dbmail.conf-dist
	@if [ ! -f ${PREFIX}/etc/dbmail.conf ] ; then \
		${CP} -p ${PREFIX}/etc/dbmail.conf-dist ${PREFIX}/etc/dbmail.conf; \
	fi
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/dbmail.schema ${DATADIR}
	@for f in mysql oracle postgresql sqlite; do \
		${MKDIR} ${DATADIR}/$$f ; \
		${INSTALL_DATA} ${WRKSRC}/sql/$$f/* ${DATADIR}/$$f; \
	done
	@${MKDIR} ${PIDDIR}
	@${CHOWN} ${DBMAIL_USER}:${DBMAIL_GROUP} ${PIDDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} * ${DOCSDIR})
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
