PORTNAME=	prawn-templates
PORTVERSION=	0.1.2
CATEGORIES=	print rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Include other pdfs or combine several pdf documents into one

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/GPLv2
LICENSE_FILE_GPLv3=	${WRKSRC}/GPLv3

RUN_DEPENDS=	rubygem-pdf-reader>=2.0<3:print/rubygem-pdf-reader \
		rubygem-prawn>=2.2<3:print/rubygem-prawn

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
