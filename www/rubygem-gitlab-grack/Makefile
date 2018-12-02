# $FreeBSD$

PORTNAME=	gitlab-grack
PORTVERSION=	2.0.2
PORTREVISION=	3
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby/Rack Git Smart-HTTP Server Handler

LICENSE=	MIT

RUN_DEPENDS=	rubygem-rack15>=1.5.1:www/rubygem-rack15

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e '/s.executables = \["console".freeze, "testserver".freeze\]/d; s|"bin/console".freeze, "bin/testserver".freeze, ||' ${WRKSRC}/${GEMSPEC}

.include <bsd.port.mk>
