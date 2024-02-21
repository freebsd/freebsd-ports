PORTNAME=	spreadsheet
PORTVERSION=	1.3.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby module to generate Microsoft Excel compatible files
WWW=		https://github.com/zdavatz/spreadsheet

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-bigdecimal>=0:math/rubygem-bigdecimal \
		rubygem-ruby-ole>=0:devel/rubygem-ruby-ole

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/xlsopcodes

.include <bsd.port.mk>
