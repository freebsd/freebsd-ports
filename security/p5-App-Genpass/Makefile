# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	App-Genpass
PORTVERSION=	2.33
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:XSAWYERX
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Quickly and easily create secure passwords

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Config-Any>=0:${PORTSDIR}/devel/p5-Config-Any \
		p5-File-HomeDir>=0:${PORTSDIR}/devel/p5-File-HomeDir \
		p5-List-AllUtils>=0:${PORTSDIR}/devel/p5-List-AllUtils \
		p5-Moo>=0:${PORTSDIR}/devel/p5-Moo \
		p5-MooX-Types-MooseLike>=0:${PORTSDIR}/devel/p5-MooX-Types-MooseLike \
		p5-namespace-clean>=0.20:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep

USE_PERL5=	configure
USES=		perl5
REINPLACE_ARGS=	-i ''

MAN1=		genpass.1
MAN3=		App::Genpass.3

post-patch:
	@${REINPLACE_CMD} -e '1 s|.*|#!${PERL}|' ${WRKSRC}/bin/genpass

.include <bsd.port.mk>
