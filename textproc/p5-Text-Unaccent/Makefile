PORTNAME=	Text-Unaccent
PORTVERSION=	1.08
PORTREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Remove accents from a string

LICENSE=	GPLv2

USES=		iconv perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} 's/-liconv/${ICONV_LIB}/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
