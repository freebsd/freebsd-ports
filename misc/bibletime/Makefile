PORTNAME=	bibletime
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.0
CATEGORIES=	misc kde

MAINTAINER=	ericbsd@FreeBSD.org
COMMENT=	Open source Bible study tool
WWW=		https://www.bibletime.info/

LICENSE=	GPLv2

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	requires 64-bit platform (sizeof(qsizetype) must be 8)

BUILD_DEPENDS=	fop:textproc/fop \
		pkgconf:devel/pkgconf \
		po4a:textproc/po4a \
		vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libclucene-core.so:textproc/clucene \
		libsword.so:misc/sword

USES=		cmake compiler:c++17-lang gl qt:6 ssl
USE_GITHUB=	yes
GH_ACCOUNT=	bibletime
USE_GL=		opengl
USE_QT=		5compat base declarative multimedia speech svg webengine \
		tools:build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
