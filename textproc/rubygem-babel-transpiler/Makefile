PORTNAME=	babel-transpiler
PORTVERSION=	0.7.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby Babel is a bridge to the JS Babel transpiler
WWW=		https://github.com/babel/ruby-babel-transpiler

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-babel-source>=4.0:textproc/rubygem-babel-source \
		rubygem-execjs>=2.0:devel/rubygem-execjs

NO_ARCH=	yes
USES=		gem

.include <bsd.port.mk>
