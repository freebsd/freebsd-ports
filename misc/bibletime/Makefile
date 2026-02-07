PORTNAME=	bibletime
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.1
CATEGORIES=	misc kde

MAINTAINER=	ericbsd@FreeBSD.org
COMMENT=	Open source Bible study tool
WWW=		https://www.bibletime.info/

LICENSE=	GPLv2

BUILD_DEPENDS=	po4a:textproc/po4a \
		fop:textproc/fop
LIB_DEPENDS=	libclucene-core.so:textproc/clucene \
		libsword.so:misc/sword

USES=		cmake compiler:c++17-lang qt:6 ssl
USE_GITHUB=	yes
GH_ACCOUNT=	bibletime
USE_QT=		5compat declarative svg webengine tools:build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
