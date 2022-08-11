PORTNAME=	spreadsheet
PORTVERSION=	1.3.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby module to generate Microsoft Excel compatible files

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-ruby-ole>=0:devel/rubygem-ruby-ole

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/xlsopcodes

.include <bsd.port.mk>
