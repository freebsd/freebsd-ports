# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	WWW-Google-SiteMap
PORTVERSION=	1.10
CATEGORIES=	textproc www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JASONK
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl extension for managing Google SiteMaps

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-XML-Twig>=0:${PORTSDIR}/textproc/p5-XML-Twig \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
