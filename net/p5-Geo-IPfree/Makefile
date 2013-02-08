# $FreeBSD$

PORTNAME=	Geo-IPfree
PORTVERSION=	1.130110
CATEGORIES=	net perl5 geography
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Look up country from an IP Address

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

PERL_CONFIGURE=	yes

MAN3=		Geo::IPfree.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501200
BUILD_DEPENDS+=	p5-Memoize>=0:${PORTSDIR}/devel/p5-Memoize
RUN_DEPENDS+=	p5-Memoize>=0:${PORTSDIR}/devel/p5-Memoize
.endif

.include <bsd.port.post.mk>
