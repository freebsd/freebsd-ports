PORTNAME=	XML-TinyXML
PORTVERSION=	0.34
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	info@rickvanderzwet.nl
COMMENT=	Little and efficient Perl module to manage xml data

USES=		iconv perl5
USE_PERL5=	configure

CONFIGURE_ARGS=	LIBS="-L${LOCALBASE}/lib ${ICONV_LIB}" \
		INC="-I. -I${LOCALBASE}/include"
CFLAGS+=	-DUSE_ICONV

.include <bsd.port.mk>
