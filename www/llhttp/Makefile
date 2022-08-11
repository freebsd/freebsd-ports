PORTNAME=	llhttp
PORTVERSION=	6.0.7
DISTVERSIONPREFIX=	 release/v
CATEGORIES=	www

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Port of http_parser to llparse

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

USES=		cmake cpe

CMAKE_ON=	BUILD_SHARED_LIBS BUILD_STATIC_LIBS

GH_ACCOUNT=	nodejs
USE_GITHUB=	yes

post-patch:
	@${CP} ${FILESDIR}/libllhttp.pc.in ${WRKSRC}/libllhttp.pc.in

.include <bsd.port.mk>
