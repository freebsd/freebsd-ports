# New ports collection makefile for:	math/p5-Set-Window
# Date created:				03 January 2001
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	Set-Window
PORTVERSION=	1.01
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Set
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Perl module to manage an interval on the integer line

PERL_CONFIGURE=	yes

MAN3=		Set::Window.3

post-patch:
	${PERL} -pi -e '$$_="" if /use 5/;' ${WRKSRC}/Window.pm

.include <bsd.port.mk>
