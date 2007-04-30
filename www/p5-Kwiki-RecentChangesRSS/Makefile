# New ports collection makefile for:	p5-Kwiki-RecentChangesRSS
# Date created:				Jul 24 2004
# Whom:	      				Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	Kwiki-RecentChangesRSS
PORTVERSION=	0.07
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Kwiki
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Kwiki RSS Plugin

BUILD_DEPENDS=	${SITE_PERL}/XML/RSS.pm:${PORTSDIR}/textproc/p5-XML-RSS
RUN_DEPENDS=	${BUILD_DEPENDS}

DEPRECATED=		already bundled in www/p5-Kwiki (0.39 or latter)
EXPIRATION_DATE=	2007-07-28
IGNORE=		${DEPRECATED}

PERL_CONFIGURE=	yes

MAN3=		Kwiki::RecentChangesRSS.3

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
