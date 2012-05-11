# New ports collection makefile for:	SVG
# Date created:		21 Nov 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	SVG
PORTVERSION=	2.51
CATEGORIES=	textproc graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for generating Scalable Vector Graphics (SVG) documents

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

PERL_CONFIGURE=	yes

MAN3=		SVG.3 SVG::DOM.3 SVG::Element.3 SVG::Extension.3 \
		SVG::Manual.3 SVG::XML.3

post-patch:
	@${FIND} ${WRKSRC} \( -name "*.p[lm]" -or -name "*.cgi" \
		-or -name "*.pod" \)|${XARGS} ${PERL} -pi -e 's/\x0d//g;'

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
