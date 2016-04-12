# Created by: Gerrit Beine <gerrit.beine@gmx.de>
# $FreeBSD$

PORTNAME=	Nagios-Plugin
PORTVERSION=	0.36
PORTREVISION=	1
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TONVOON
PKGNAMEPREFIX=	p5-

MAINTAINER=	gjb@FreeBSD.org
COMMENT=	Modules to streamline writing Nagios plugins

BUILD_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Params-Validate>=0:devel/p5-Params-Validate \
		p5-Math-Calc-Units>=0:math/p5-Math-Calc-Units \
		p5-Config-Tiny>=0:devel/p5-Config-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
