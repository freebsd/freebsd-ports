# Created by: will
# $FreeBSD$

PORTNAME=	Crypt-Cracklib
PORTVERSION=	1.7
PORTREVISION=	5
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to Alec Muffet's cracklib library

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

LIB_DEPENDS=	libcrack.so:security/cracklib

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	INC="-I${LOCALBASE}/include" DEFINE="-DCRACKLIB_DICTPATH=\\\"${PREFIX}/libdata/cracklib/pw_dict\\\""

post-patch:
	@${REINPLACE_CMD} 's/-Werror//' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
