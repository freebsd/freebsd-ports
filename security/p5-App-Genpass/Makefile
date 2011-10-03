# New ports collection makefile for:	p5-App-Genpass
# Date created:		2011-10-03
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	App-Genpass
PORTVERSION=	2.10
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Quickly and easily create secure passwords

BUILD_DEPENDS=	p5-Config-Any>=0:${PORTSDIR}/devel/p5-Config-Any \
		p5-File-HomeDir>=0:${PORTSDIR}/devel/p5-File-HomeDir \
		p5-List-AllUtils>=0:${PORTSDIR}/devel/p5-List-AllUtils \
		p5-Mouse>=0:${PORTSDIR}/devel/p5-Mouse \
		p5-MouseX-ConfigFromFile>=0:${PORTSDIR}/devel/p5-MouseX-ConfigFromFile \
		p5-MouseX-Getopt>=0:${PORTSDIR}/devel/p5-MouseX-Getopt \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean \
		p5-namespace-clean>=0.20:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep

PERL_CONFIGURE=	yes
REINPLACE_ARGS=	-i ''

MAN1=		genpass.1
MAN3=		App::Genpass.3

post-patch:
	@${REINPLACE_CMD} -e '1 s|.*|#!${PERL}|' ${WRKSRC}/bin/genpass

.include <bsd.port.mk>
