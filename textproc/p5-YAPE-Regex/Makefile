# New ports collection makefile for:	p5-YAPE-Regex
# Date created:	   3 juin 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	YAPE-Regex
PORTVERSION=	3.01
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/P/PI/PINYAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Yet Another Parser/Extractor for Regular Expressions

BUILD_DEPENDS=	${SITE_PERL}/Text/Balanced.pm:${PORTSDIR}/textproc/p5-Text-Balanced
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		YAPE::Regex.3 YAPE::Regex::Element.3

.include <bsd.port.mk>
