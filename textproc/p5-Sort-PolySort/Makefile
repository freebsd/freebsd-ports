# New ports collection makefile for:	textproc/p5-Sort-PolySort
# Date created:				12 June 2001
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Sort-PolySort
PORTVERSION=	0.12
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Sort
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org

PERL_CONFIGURE=	yes

MAN3=		Sort::PolySort.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

pre-patch:
	@${PERL} -pi -e '/^\$$Sort::PolySort::VERSION =/ && chomp' \
		${WRKSRC}/lib/Sort/PolySort.pm

.include <bsd.port.mk>
