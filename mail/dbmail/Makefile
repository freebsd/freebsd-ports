# New ports collection makefile for:	dbmail
# Date created:				07/26/2003
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	dbmail
PORTVERSION=	3.0.2
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
		zdb.8:${PORTSDIR}/databases/libzdb \
		mhash.2:${PORTSDIR}/security/mhash \
		event-1.4:${PORTSDIR}/devel/libevent

CONFLICTS=	dbmail-*-2.0.* dbmail-2.*

OPTIONS=	SIEVE	"Build with support for Sieve mail sorting language" off \
		LDAP	"Build with support for LDAP authentication" off

USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_LDCONFIG=	${PREFIX}/lib/dbmail
USE_RC_SUBR=	dbmail-pop3d dbmail-lmtpd dbmail-imapd dbmail-timsieved
USE_OPENSSL=	yes

CFLAGS+=	-fPIC -I${LOCALBASE}/include ${PTHREAD_CFLAGS}
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

.include <bsd.port.pre.mk>

.if defined(WITH_SIEVE)
CONFIGURE_ARGS+=--with-sieve=${LOCALBASE}
LIB_DEPENDS+=	sieve.1:${PORTSDIR}/mail/libsieve
PLIST_SUB+=	SIEVE=""
.else
PLIST_SUB+=	SIEVE="@comment "
.endif

.if defined(WITH_LDAP)
CONFIGURE_ARGS+=--with-ldap=${LOCALBASE}
USE_OPENLDAP=	yes
PLIST_SUB+=	LDAP=""
.else
PLIST_SUB+=	LDAP="@comment "
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

.include <bsd.port.post.mk>
