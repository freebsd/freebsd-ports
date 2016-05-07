# $FreeBSD$

PORTNAME=	Plack-Handler-AnyEvent-SCGI
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for PSGI handler on AnyEvent::SCGI

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-AnyEvent-SCGI>0:www/p5-AnyEvent-SCGI \
	p5-Plack>=0.9901:www/p5-Plack
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-TCP>0:devel/p5-Test-TCP

USES=		perl5
USE_PERL5=	modbuildtiny
NO_ARCH=	YES

# Workaround until Module::Build::Tiny 0.039.
post-patch:
	${REINPLACE_CMD} -e 's|0.039|0.038|' ${WRKSRC}/Build.PL

.include <bsd.port.mk>
