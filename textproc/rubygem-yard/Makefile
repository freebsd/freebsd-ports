# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	yard
PORTVERSION=	0.9.27
CATEGORIES=	textproc devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Documentation generation tool for Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-webrick>=1.7.0<1.8:www/rubygem-webrick

USES=		cpe gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/yard \
		bin/yardoc \
		bin/yri

CPE_VENDOR=	yardoc

.include <bsd.port.mk>
