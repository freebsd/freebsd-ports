PORTNAME=	caronade
DISTVERSIONPREFIX=v
DISTVERSION=	0.5.0
PORTREVISION=	4
CATEGORIES=	ports-mgmt

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Small and light tool to help with FreeBSD Ports CI

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	sassc:textproc/sassc

USES=		go:modules,no_targets
USE_RC_SUBR=	caronade

GO_MODULE=	github.com/decke/caronade

MAKE_ENV+=	GO_BUILDFLAGS="${GO_BUILDFLAGS}"

.include <bsd.port.mk>
