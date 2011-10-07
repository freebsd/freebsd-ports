# New ports collection makefile for:	Crypt-Cracklib
# Date created:				Fri Jan 26 20:26:11 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Crypt-Cracklib
PORTVERSION=	1.7
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to Alec Muffet's cracklib library

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/lib/libcrack.a:${PORTSDIR}/security/cracklib \
		p5-Pod-Coverage>=0.19:${PORTSDIR}/devel/p5-Pod-Coverage \
		p5-Test-Pod-Coverage>=1.08:${PORTSDIR}/devel/p5-Test-Pod-Coverage
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	INC="-I${LOCALBASE}/include" DEFINE="-DCRACKLIB_DICTPATH=\\\"${PREFIX}/libdata/cracklib/pw_dict\\\""

MAN3=		Crypt::Cracklib.3

post-patch:
	${REINPLACE_CMD} -e 's/crack.h/packer.h/' ${WRKSRC}/Cracklib.*

.include <bsd.port.mk>
