# Created by: Daniel B. Hemmerich <dan@spot.org>
# $FreeBSD$

PORTNAME=	Text-FIGlet
PORTVERSION=	2.19.3
PORTREVISION=	2
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl module to provide FIGlet abilities, akin to banner

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	figlet:misc/figlet
TEST_DEPENDS=	p5-Test-Differences>=0:devel/p5-Test-Differences \
		p5-Test-Pod>=1:devel/p5-Test-Pod

NO_ARCH=	yes
REINPLACE_ARGS=	-i ''
USE_PERL5=	configure
USES=		perl5 tar:tgz

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/games/lib|${PREFIX}/share|' ${WRKSRC}/bin/*.pl ${WRKSRC}/lib/Text/FIGlet.pm ${WRKSRC}/lib/Text/FIGlet/*.pm

.include <bsd.port.mk>
