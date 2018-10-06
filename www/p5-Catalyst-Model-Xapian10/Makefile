# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Model-Xapian
PORTVERSION=	0.06
PORTREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MRAMBERG
PKGNAMEPREFIX=	p5-
PKGNAMESUFFIX=	10

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Catalyst model for Search::Xapian

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Catalyst-Runtime>=5.30:www/p5-Catalyst-Runtime \
		p5-Catalyst-Devel>=1.00:www/p5-Catalyst-Devel \
		p5-Data-Page>=0:databases/p5-Data-Page \
		p5-Search-Xapian10>=0.9.2.4:databases/p5-Search-Xapian10

NO_ARCH=	yes
USES=		perl5 shebangfix
USE_PERL5=	configure

SHEBANG_FILES=	sample-indexer.pl

.include <bsd.port.mk>
