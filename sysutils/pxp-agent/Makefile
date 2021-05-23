PORTNAME=	pxp-agent
PORTVERSION=	1.15.11
CATEGORIES=	sysutils

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	PCP eXecution Protocol Agent

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	liblibcpp-pcp-client.so:net/cpp-pcp-client \
		libboost_thread.so:devel/boost-libs \
		liblibcpp-hocon.so:devel/cpp-hocon \
		libleatherman_util.so:devel/leatherman

USES=		cmake ssl
USE_GITHUB=	yes

GH_ACCOUNT=	puppetlabs

CMAKE_OFF=	ENABLE_CXX_WERROR
LDFLAGS+=	-lthr

.include <bsd.port.mk>
