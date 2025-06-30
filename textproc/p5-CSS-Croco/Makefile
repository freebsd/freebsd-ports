PORTNAME=	CSS-Croco
PORTVERSION=	0.09
PORTREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Quick CSS parser
WWW=		https://metacpan.org/release/CSS-Croco

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-URI>=0:net/p5-URI
LIB_DEPENDS=	libcroco-0.6.so:textproc/libcroco

USES=		perl5 pkgconfig
USE_PERL5=	configure

.include <bsd.port.mk>
