# Created by: Lars Thegler <lars@thegler.dk>
# $FreeBSD$

PORTNAME=	Sys-CpuLoad
PORTVERSION=	0.21
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module to retrieve CPU load averages

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	p5-Test-Most>=0:devel/p5-Test-Most

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Sys/CpuLoad/CpuLoad.so

.include <bsd.port.mk>
