# Created by: Michael Moll <kvedulv@kvedulv.de>
# $FreeBSD$

PORTNAME=	jekyll-paginate
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Built-in Pagination Generator for Jekyll

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem shebangfix
SHEBANG_FILES=	script/bootstrap \
		script/cibuild \
		script/unbundle

.include <bsd.port.mk>
