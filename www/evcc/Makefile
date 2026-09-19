PORTNAME=	evcc
DISTVERSION=	0.315.2
CATEGORIES=	www
MASTER_SITES=	LOCAL/mfechner/${PORTNAME}/:vpcache
DISTFILES=	${PORTNAME}-vp-cache-${DISTVERSION}${EXTRACT_SUFX}:vpcache

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Extensible EV Charge Controller
WWW=		https://evcc.io/ \
		https://github.com/evcc-io/evcc

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	Npm cache only for amd64 generated

BUILD_DEPENDS=	vite-plus>0:devel/vite-plus

USES=		gmake go:1.27+,modules,no_targets nodejs:26,build tar:zstd

# Find here: https://github.com/evcc-io/evcc/releases
_SHA=		f9cf626eef7a9813040ef2a07bc84f24ace7d913

USE_GITHUB=	yes
GH_ACCOUNT=	evcc-io
USE_RC_SUBR=	${PORTNAME}
GO_MOD_DIST=	github
GO_MODULE=	github.com/evcc-io/evccmain

MAKE_ENV=	npm_config_offline=true TAG_NAME=${DISTVERSION} SHA=${_SHA}

# parallel build failed in my tests, so disable it here
MAKE_JOBS_UNSAFE=yes
ALL_TARGET=	default

USERS=		evcc
GROUPS=		evcc

PLIST_FILES=	bin/${PORTNAME}

pre-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} vp env off
	@echo '{"latest":"","checked_at":'`/bin/date +1"%s"`',"prompted_at":0}' > ${WRKDIR}/.vite-plus/.upgrade-check.json
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} vp install --offline --ignore-scripts --frozen-lockfile
	@${CP} -f ${LOCALBASE}/lib/vite-plus/libvite_plus_cli.so ${WRKSRC}/node_modules/vite-plus/binding/vite-plus.freebsd-x64.node
	@${CP} -f ${LOCALBASE}/lib/vite-plus/librolldown_binding.so ${WRKSRC}/node_modules/vite/dist/rolldown/shared/rolldown-binding.freebsd-x64.node
	@${CP} -f ${LOCALBASE}/lib/vite-plus/librolldown_binding.so ${WRKSRC}/node_modules/@voidzero-dev/vite-plus-core/dist/rolldown/shared/rolldown-binding.freebsd-x64.node

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/evcc ${STAGEDIR}${PREFIX}/bin

# (for maintainer) helper target to generate node_modules tarball
make-vp-cache: patch
	@cd ${WRKDIR} && ${RM} -r .npm
	@cd ${WRKSRC} && ${SETENV} HOME=${WRKDIR} vp env off
	@cd ${WRKSRC} && ${SETENV} HOME=${WRKDIR} vp install --ignore-scripts
	@cd ${WRKDIR} \
		&& ${TAR} -c --zstd -f ${PORTNAME}-vp-cache-${DISTVERSION}${EXTRACT_SUFX} .npm .vite-plus \
		&& ${ECHO} "Please upload the file: scp ${WRKDIR}/${PORTNAME}-vp-cache-${DISTVERSION}${EXTRACT_SUFX} mfechner@freefall.freebsd.org:public_distfiles/${PORTNAME}/"

.include <bsd.port.mk>
