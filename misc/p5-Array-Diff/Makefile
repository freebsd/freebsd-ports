# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Array-Diff
PORTVERSION=	0.08
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Diff two arrays

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Algorithm-Diff>=1.19:devel/p5-Algorithm-Diff \
		p5-Class-Accessor>=0:devel/p5-Class-Accessor

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes
.include <bsd.port.mk>
