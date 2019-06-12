# $FreeBSD$

PORTNAME=	caronade
DISTVERSIONPREFIX=v
DISTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	ports-mgmt
MASTER_SITES=	https://code.bluelife.at/decke/caronade/archive/ \
		LOCAL/decke/caronade/
DISTFILES=	${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Small and light tool to help with FreeBSD Ports CI

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_RC_SUBR=	caronade

USE_GITHUB=	nodefault
GH_TUPLE=	NYTimes:gziphandler:v1.1.1:gziphandler/vendor/github.com/NYTimes/gziphandler \
		go-yaml:yaml:v2.2.2:yaml/vendor/gopkg.in/yaml.v2

GO_PKGNAME=	code.bluelife.at/decke/caronade
MAKE_ENV+=	GOFLAGS=-mod=vendor

post-install:
		${MKDIR} ${STAGEDIR}${ETCDIR}
		${INSTALL_DATA} ${WRKSRC}/caronade.yaml ${STAGEDIR}${ETCDIR}/caronade.yaml.sample

		${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}
		(cd ${WRKSRC} && ${COPYTREE_SHARE} "static templates work" ${STAGEDIR}${PREFIX}/${PORTNAME})

		${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}/builds

.include <bsd.port.mk>
