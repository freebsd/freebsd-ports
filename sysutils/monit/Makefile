# New ports collection makefile for:   monit
# Date created:        4 January 2005
# Whom:                Martin Pala <martinp@tildeslash.com>
#
# $FreeBSD$
#

PORTNAME=	monit
PORTVERSION=	5.4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.mmonit.com/monit/dist/

MAINTAINER=	martinp@tildeslash.com
COMMENT=	Unix system management and proactive monitoring

MAN1=		monit.1

GNU_CONFIGURE=	yes
USE_BISON=	build
USE_GMAKE=	yes
USE_RC_SUBR=	${PORTNAME}

CONFIGURE_ENV=	CONFIG_SHELL="${SH}" \
		LOCALBASE="${LOCALBASE}"

OPTIONS=	SSL "Enable SSL support" on

PLIST_FILES=	bin/monit \
		etc/monitrc.sample

SUB_FILES=	pkg-message

DOCS=		CHANGES COPYING README
PORTDOCS=	${DOCS:T}

.include <bsd.port.options.mk>

.if defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	--without-ssl
.endif

post-install:
	${INSTALL} -m 600 ${WRKSRC}/monitrc ${PREFIX}/etc/monitrc.sample
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL} -m 644 ${DOCS} ${DOCSDIR}/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
