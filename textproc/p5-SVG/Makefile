# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	SVG
PORTVERSION=	2.59
CATEGORIES=	textproc graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for generating Scalable Vector Graphics (SVG) documents

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

OPTIONS_DEFINE=	EXAMPLES

USES=		perl5
USE_PERL5=	configure
USE_DOS2UNIX=	yes

MAN3=		SVG.3 SVG::DOM.3 SVG::Element.3 SVG::Extension.3 \
		SVG::XML.3

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	${MKDIR} ${EXAMPLESDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
