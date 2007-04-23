# New ports collection makefile for:	p5-Kwiki-UserPreferences
# Date created:				Jul 24 2004
# Whom:	      				Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	Kwiki-UserPreferences
PORTVERSION=	0.13
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Kwiki
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Kwiki User Preferences Plugin

BUILD_DEPENDS=	${SITE_PERL}/Kwiki.pm:${PORTSDIR}/www/p5-Kwiki
RUN_DEPENDS=	${BUILD_DEPENDS}

DEPRECATED=		Already bundled in www/p5-Kwiki (0.39 or latter)
EXPIRATION_DATE=	2007-07-28
BROKEN=		${DEPRECATED}

PERL_CONFIGURE=	yes

MAN3=		Kwiki::UserPreferences.3

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
