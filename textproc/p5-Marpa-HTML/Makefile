# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Marpa-HTML
PORTVERSION=	0.112
DISTVERSIONSUFFIX=	000
PORTREVISION=	1
CATEGORIES=	textproc lang perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JKEGL
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	High-level HTML Parser

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTML-Parser>=3.64:www/p5-HTML-Parser \
		p5-Marpa-PP>=0.012:lang/p5-Marpa-PP \
		p5-Marpa-XS>=0.026:lang/p5-Marpa-XS
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	modbuild
USES=		perl5

post-patch:
	@${REINPLACE_CMD} -e 's|lib/Marpa/Support.pod|lib/Marpa/HTML/Support.pod|' ${WRKSRC}/Build.PL

.include <bsd.port.mk>
