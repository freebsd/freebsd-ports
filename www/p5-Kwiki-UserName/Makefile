# New ports collection makefile for:	p5-Kwiki-UserName
# Date created:				Jul 24 2004
# Whom:	      				Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	Kwiki-UserName
PORTVERSION=	0.14
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Kwiki
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Kwiki User Name Plugin

BUILD_DEPENDS=	${SITE_PERL}/Kwiki.pm:${PORTSDIR}/www/p5-Kwiki \
		${SITE_PERL}/Kwiki/UserPreferences.pm:${PORTSDIR}/www/p5-Kwiki-UserPreferences
RUN_DEPENDS=	${BUILD_DEPENDS}

DEPRECATED=		already bundled in www/p5-Kwiki (0.39 or latter)
EXPIRATION_DATE=	2007-07-28
IGNORE=		${DEPRECATED}

PERL_CONFIGURE=	yes

MAN3=		Kwiki::UserName.3

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
