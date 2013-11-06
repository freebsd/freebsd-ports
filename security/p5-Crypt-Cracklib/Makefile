# Created by: will
# $FreeBSD$

PORTNAME=	Crypt-Cracklib
PORTVERSION=	1.7
PORTREVISION=	2
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to Alec Muffet's cracklib library

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Pod-Coverage>=0.19:${PORTSDIR}/devel/p5-Pod-Coverage \
		p5-Test-Pod-Coverage>=1.08:${PORTSDIR}/devel/p5-Test-Pod-Coverage
RUN_DEPENDS:=	${BUILD_DEPENDS}
LIB_DEPENDS=	libcrack.so:${PORTSDIR}/security/cracklib

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	INC="-I${LOCALBASE}/include" DEFINE="-DCRACKLIB_DICTPATH=\\\"${PREFIX}/libdata/cracklib/pw_dict\\\""

.include <bsd.port.mk>
