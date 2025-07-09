PORTNAME=	mailpit
DISTVERSIONPREFIX=	v
DISTVERSION=	1.27.1
PORTREVISION=	1
CATEGORIES=	mail devel
MASTER_SITES=	https://www.madpilot.net/mailpit/:npmcache \
		LOCAL/madpilot/mailpit:npmcache
DISTFILES=	${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX}:npmcache

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Mailpit development mail server
WWW=		https://github.com/axllent/mailpit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	dependency modernc.org/sqlite only supported on these

BUILD_DEPENDS=	npm>0:www/npm

USES=		go:1.24,modules tar:zstd
USE_RC_SUBR=	mailpit
GO_MODULE=	github.com/axllent/mailpit
GO_BUILDFLAGS=	-ldflags="-s -w -X \"github.com/axllent/mailpit/config.Version=${DISTVERSIONPREFIX}${DISTVERSION}\""
MAKE_ENV=	npm_config_offline=true

SUB_FILES=	pkg-message
PLIST_FILES=	bin/${PORTNAME}

pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm ci --legacy-peer-deps
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm run build

# (for maintainer) helper target to generate node_modules tarball
make-npm-cache: patch
	@cd ${WRKDIR} && ${RM} -r .npm
	@cd ${WRKSRC} && ${SETENV} HOME=${WRKDIR} npm ci --legacy-peer-deps
	@cd ${WRKDIR} \
		&& ${TAR} -c --zstd -f ${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX} .npm \
		&& ${ECHO} "Please upload the file ${WRKDIR}/${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX}"

.include <bsd.port.mk>
