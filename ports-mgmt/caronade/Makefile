PORTNAME=	caronade
DISTVERSIONPREFIX=v
DISTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	ports-mgmt

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Small and light tool to help with FreeBSD Ports CI
WWW=		https://codeberg.org/decke/caronade

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	minify:textproc/minify

USES=		go:modules,no_targets
USE_RC_SUBR=	caronade

GO_MODULE=	codeberg.org/decke/caronade

MAKE_ENV+=	GO_BUILDFLAGS="${GO_BUILDFLAGS}"

.include <bsd.port.mk>
