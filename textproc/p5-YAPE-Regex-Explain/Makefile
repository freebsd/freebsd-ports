# New ports collection makefile for:	p5-YAPE-Regex-Explain
# Date created:	   3 juin 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	YAPE-Regex-Explain
PORTVERSION=	3.011
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/P/PI/PINYAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Explanation of a Regular Expression

BUILD_DEPENDS=	${SITE_PERL}/YAPE/Regex.pm:${PORTSDIR}/textproc/p5-YAPE-Regex
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		YAPE::Regex::Explain.3

.include <bsd.port.mk>
