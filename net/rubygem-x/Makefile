PORTNAME=	x
PORTVERSION=	1.0.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby interface to the X API
WWW=		https://sferik.github.io/x-ruby/ \
		https://github.com/sferik/x-ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-x-core>=${PORTVERSION}<${PORTVERSION}_99:net/rubygem-x-core \
		rubygem-x-resources>=${PORTVERSION}<${PORTVERSION}_99:net/rubygem-x-resources \
		rubygem-x-streams>=${PORTVERSION}<${PORTVERSION}_99:net/rubygem-x-streams \
		rubygem-x-uploads>=${PORTVERSION}<${PORTVERSION}_99:net/rubygem-x-uploads

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
