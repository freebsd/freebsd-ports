# New ports collection makefile for:	p5-YAPE-Regex-Explain
# Date created:	   3 juin 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	YAPE-Regex-Explain
PORTVERSION=	4.01
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/G/GS/GSULLIVAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Explanation of a Regular Expression

RUN_DEPENDS=	p5-YAPE-Regex>=0:${PORTSDIR}/textproc/p5-YAPE-Regex
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		YAPE::Regex::Explain.3

.include <bsd.port.mk>
