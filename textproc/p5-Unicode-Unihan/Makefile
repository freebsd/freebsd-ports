# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Unicode-Unihan
DISTVERSION=	0.04
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	The Unihan Data Base 5.1.0

USES=		perl5
USE_PERL5=	configure

MAN3=		Unicode::Unihan.3

post-patch:
	@${REINPLACE_CMD} -e '/use 5.008001;/d' ${WRKSRC}/Unihan.pm

.include <bsd.port.mk>
