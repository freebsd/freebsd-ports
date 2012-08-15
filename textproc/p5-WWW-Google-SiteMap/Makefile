# New ports collection makefile for:	p5-WWW-Google-SiteMap
# Date created:				2006-04-15
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	WWW-Google-SiteMap
PORTVERSION=	1.10
CATEGORIES=	textproc www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl extension for managing Google SiteMaps

BUILD_DEPENDS=	p5-XML-Twig>=0:${PORTSDIR}/textproc/p5-XML-Twig \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WWW::Google::SiteMap.3		\
		WWW::Google::SiteMap::Index.3	\
		WWW::Google::SiteMap::Ping.3	\
		WWW::Google::SiteMap::Robot.3	\
		WWW::Google::SiteMap::URL.3

.include <bsd.port.mk>
