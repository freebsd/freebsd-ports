PORTNAME=	librespeed-go
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.5
PORTREVISION=	2
CATEGORIES=	net www

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	GO backend for LibreSpeed

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_RC_SUBR=	librespeed-go

GO_MODULE=	github.com/librespeed/speedtest-go

SUB_FILES=	pkg-message
SUB_LIST=	LIBRESPEED_USER=${USERS} LIBRESPEED_GROUP=${GROUPS} PORTNAME=${PORTNAME}

USERS=		librespeed
GROUPS=		librespeed

PLIST_SUB=	LIBRESPEED_USER=${USERS} LIBRESPEED_GROUP=${GROUPS}

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	${REINPLACE_CMD} -e 's|"."|"${ETCDIR}"|g' ${WRKSRC}/config/config.go

pre-install:
	${REINPLACE_CMD} -e 's|assets_path=""|assets_path="${WWWDIR}"|g' ${WRKSRC}/settings.toml
	${REINPLACE_CMD} -e 's|speedtest.db|/var/db/${PORTNAME}/speedtest.db|g' ${WRKSRC}/settings.toml

post-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${CP} -a ${WRKSRC}/web/assets/*.js ${STAGEDIR}${WWWDIR}
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/settings.toml ${STAGEDIR}${ETCDIR}/settings.toml.sample
	${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}
	${MKDIR} ${STAGEDIR}/var/run/${PORTNAME}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -a ${WRKSRC}/web/assets/*.html ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
