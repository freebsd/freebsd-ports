PORTNAME=	vikunja
DISTVERSIONPREFIX=v
DISTVERSION=	2.3.0
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	LOCAL/decke:ui
DISTFILES=	vikunja-frontend-${DISTVERSION}.tar.gz:ui

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Todo-app to organize your life
WWW=		https://vikunja.io

LICENSE=	AGPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	go-vikunja

USE_RC_SUBR=	vikunja

GO_MODULE=	code.vikunja.io/api
GO_MOD_DIST=	https://raw.githubusercontent.com/go-vikunja/vikunja/refs/tags/v${DISTVERSION}/
GO_BUILDFLAGS=	-tags osusergo -ldflags " \
		-X code.vikunja.io/api/pkg/version.Version=${DISTVERSION} \
		-X main.Tags=osusergo"

post-extract:
	${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/vikunja-frontend-${DISTVERSION}.tar.gz -C ${WRKSRC}/frontend

post-install:
	${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}
	${MKDIR} ${STAGEDIR}/var/log/${PORTNAME}
	${MKDIR} ${STAGEDIR}/var/run/${PORTNAME}
	${INSTALL_DATA} ${PATCHDIR}/config.yml.sample ${STAGEDIR}/var/db/${PORTNAME}/config.yml.sample

.include <bsd.port.mk>
