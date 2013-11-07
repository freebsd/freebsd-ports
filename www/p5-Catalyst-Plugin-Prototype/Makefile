# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-Prototype
PORTVERSION=	1.33
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MRAMBERG
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Catalyst plugin for Prototype

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7006:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Devel>=1.00:${PORTSDIR}/www/p5-Catalyst-Devel \
		p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-HTML-Prototype>=1.48:${PORTSDIR}/www/p5-HTML-Prototype
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-extract:
	@${FIND} ${WRKSRC} -name '._Prototype.pm' -delete

.include <bsd.port.mk>
