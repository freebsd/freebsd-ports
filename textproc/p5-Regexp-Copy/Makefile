# New ports collection makefile for:	p5-Regexp-Copy
# Date created:		2007-12-24
# Whom:			Andrej Zverev <andrey.zverev@electro-com.ru>
#
# $FreeBSD$
#

PORTNAME=	Regexp-Copy
PORTVERSION=	0.06
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/J/JD/JDUNCAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A copy the contents of one Regexp object to another

BUILD_DEPENDS=	p5-ExtUtils-MakeMaker>=6.11:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Regexp::Copy.3

.include <bsd.port.mk>
