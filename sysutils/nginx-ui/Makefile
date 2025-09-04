PORTNAME=	nginx-ui
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.17
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/dtxdf/${PORTNAME}/
DISTFILES=	${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}.frontend${EXTRACT_SUFX} \
		${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}.vendor${EXTRACT_SUFX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Yet another WebUI for Nginx
WWW=		https://nginxui.com

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.25,modules
USE_GITHUB=	yes
GH_ACCOUNT=	0xJacky

USE_RC_SUBR=	${PORTNAME}

GO_BUILDFLAGS=	-ldflags "\
			-X 'github.com/0xJacky/Nginx-UI/settings.buildTime=${BUILD_DATE}'" \
		-tags=jsoniter

SUB_FILES=	pkg-message
SUB_LIST=	USER=${NGINXUI_USER}

PLIST_SUB=	GROUP=${NGINXUI_USER} \
		USER=${NGINXUI_GROUP}

NGINXUI_USER=	root
NGINXUI_GROUP=	wheel

BUILD_DATE=	$$(date -u +%s)

# Run 'git checkout ${DISTVERSIONPREFIX}${DISTVERSION} && git rev-parse HEAD'
# in the NGINX UI repository to get the value of GITID.
GITID=		876213ad12449216d82520b3808b59cdaf0e1276

post-extract:
	@${MKDIR} ${WRKSRC}/vendor
	@cd ${WRKDIR}/${PORTNAME}-vendor && ${COPYTREE_SHARE} . ${WRKSRC}/vendor
	@${MKDIR} ${WRKSRC}/app/dist
	@cd ${WRKDIR}/${PORTNAME}-frontend && ${COPYTREE_SHARE} . ${WRKSRC}/app/dist

post-patch:
	@${REINPLACE_CMD} -e 's/newLineSymbol/"\\n"/g' \
		${WRKSRC}/vendor/github.com/imega/luaformatter/formatter/writer.go
	@${REINPLACE_CMD} -e 's,%%GITID%%,${GITID},g' ${WRKSRC}/cmd/version/generate.go
	@${RM} ${WRKSRC}/vendor/github.com/shirou/gopsutil/v4/internal/common/binary.go

pre-build:
	@${SETENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=off ${GO_CMD} generate ${WRKSRC}/cmd/version/generate.go

post-install:
	@${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}
	${INSTALL_DATA} ${FILESDIR}/app.ini ${STAGEDIR}/var/db/${PORTNAME}/app.ini.sample
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${FILESDIR}/nginx-ui.conf ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${FILESDIR}/nginx.conf ${STAGEDIR}${DATADIR}
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${STAGEDIR}${DATADIR}/nginx.conf

.include <bsd.port.mk>
