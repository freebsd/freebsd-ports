PORTNAME=	prawn-table
PORTVERSION=	0.2.2
CATEGORIES=	print rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provide tables for the Prawn PDF toolkit

LICENSE=	GPLv2 GPLv3 RUBY
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/GPLv2
LICENSE_FILE_GPLv3=	${WRKSRC}/GPLv3
LICENSE_FILE_RUBY=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-prawn>=1.3.0<3.0.0:print/rubygem-prawn

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
