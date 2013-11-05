# Created by: Maxime Henrion <mux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Math-BigInt-GMP
PORTVERSION=	1.37
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Math::BigInt::GMP - Use the GMP library for Math::BigInt routines

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Math-BigInt>=1.997:${PORTSDIR}/math/p5-Math-BigInt
LIB_DEPENDS=	libgmp.so.10:${PORTSDIR}/math/gmp
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure patch
CONFIGURE_ARGS=	INC="-I${LOCALBASE}/include"

post-patch:
	@${PERL} -pi -e "s!-lgmp!-L${LOCALBASE}/lib $$&!;" \
		     -e "if (/'LIBS'/) { print qq!'INC' => '-I${LOCALBASE}/include',!; }" \
		${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
