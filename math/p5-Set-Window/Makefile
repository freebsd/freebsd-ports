# Created by: Anton Berezin <tobez@tobez.org>
# $FreeBSD$

PORTNAME=	Set-Window
PORTVERSION=	1.01
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Perl module to manage an interval on the integer line

USES=		perl5
USE_PERL5=	configure

MAN3=		Set::Window.3

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -i '' '/use 5/d' ${WRKSRC}/Window.pm

.include <bsd.port.mk>
