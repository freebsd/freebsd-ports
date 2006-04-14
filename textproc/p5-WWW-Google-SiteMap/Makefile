# New ports collection makefile for:	p5-WWW-Google-SiteMap
# Date created:				2006-04-15
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	WWW-Google-SiteMap
PORTVERSION=	1.08
CATEGORIES=	textproc www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW
PKGNAMEPREFIX=	p5-

MAINTAINER=	nork@FreeBSD.org
COMMENT=	Perl extension for managing Google SiteMaps

BUILD_DEPENDS=	${SITE_PERL}/XML/Twig.pm:${PORTSDIR}/textproc/p5-XML-Twig \
		${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WWW::Google::SiteMap.3		\
		WWW::Google::SiteMap::Index.3	\
		WWW::Google::SiteMap::Ping.3	\
		WWW::Google::SiteMap::Robot.3	\
		WWW::Google::SiteMap::URL.3

.include <bsd.port.mk>
