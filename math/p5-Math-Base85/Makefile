# New ports collection makefile for:	math/p5-Math-Base85
# Date created:				17 Sep 2001
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-Base85
PORTVERSION=	0.1
CATEGORIES=	math perl5 converters net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Math
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org

PERL_CONFIGURE=	yes

MAN3=		Math::Base85.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

# workaround the bug in 5.005_03 and 5.6.0  :-(
post-patch:
	${PERL} -pi -e 's|^use constant\s*(.*?)\s*=>.s*(.*)$$|sub $$1 { $$2 }|' ${WRKSRC}/Base85.pm

.include <bsd.port.mk>
