# New ports collection makefile for:	p5-Kwiki-GDGraphGenerator
# Date created:		2004-08-28
# Whom:			Elvis Chiang <elvis@sslab.cs.ccu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Kwiki-GDGraphGenerator
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Kwiki
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Kwiki plugin for putting pretty graphs into your Kwiki pages

BUILD_DEPENDS=	${SITE_PERL}/Kwiki.pm:${PORTSDIR}/www/p5-Kwiki \
		${SITE_PERL}/GD/Graph.pm:${PORTSDIR}/graphics/p5-GD-Graph
RUN_DEPENDS=	${BUILD_DEPENDS}

DEPRECATED=		already bundled in www/p5-Kwiki (0.39 or latter)
EXPIRATION_DATE=	2007-07-28
IGNORE=		${DEPRECATED}

PERL_CONFIGURE=	yes

MAN3=		Kwiki::GDGraphGenerator.3

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
