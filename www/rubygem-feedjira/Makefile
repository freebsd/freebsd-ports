PORTNAME=	feedjira
PORTVERSION=	4.0.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Feed fetching and parsing library
WWW=		https://github.com/feedjira/feedjira

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-logger>=1.0<2:devel/rubygem-logger \
		rubygem-loofah>=2.3.1<3:textproc/rubygem-loofah \
		rubygem-sax-machine>=1.0<2:textproc/rubygem-sax-machine

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
