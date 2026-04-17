PORTNAME=	UEFITool
DISTVERSIONPREFIX=	A
DISTVERSION=	74
CATEGORIES=	sysutils

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	UEFI images parser
WWW=		https://github.com/LongSoft/UEFITool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers

USES=		cmake compiler:c++11-lang gl qt:6
USE_GITHUB=	yes
USE_GL=		gl
USE_QT=		base

GH_ACCOUNT=	LongSoft

.include <bsd.port.mk>
