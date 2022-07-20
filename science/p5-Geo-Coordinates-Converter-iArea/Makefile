PORTNAME=	Geo-Coordinates-Converter-iArea
PORTVERSION=	0.14
PORTREVISION=	1
CATEGORIES=	science geography perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Some utility functions around iArea

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-CDB_File>=0.96:databases/p5-CDB_File \
		p5-File-ShareDir>=1.02:devel/p5-File-ShareDir \
		p5-Geo-Coordinates-Converter>=0.09:science/p5-Geo-Coordinates-Converter

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
