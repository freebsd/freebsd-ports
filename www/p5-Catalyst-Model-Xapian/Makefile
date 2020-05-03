# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Model-Xapian
PORTVERSION=	0.06
PORTREVISION=	4
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Catalyst model for Search::Xapian

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Catalyst-Devel>=1.00:www/p5-Catalyst-Devel \
		p5-Catalyst-Runtime>=5.30:www/p5-Catalyst-Runtime \
		p5-Data-Page>=0:databases/p5-Data-Page \
		p5-Search-Xapian12>=1.2.7.0:databases/p5-Search-Xapian12

USES=		perl5 shebangfix
USE_PERL5=	configure

NO_ARCH=	yes

SHEBANG_FILES=	sample-indexer.pl

.include <bsd.port.mk>
