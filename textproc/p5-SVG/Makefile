# New ports collection makefile for:	SVG
# Date created:		21 Nov 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	SVG
PORTVERSION=	2.1
CATEGORIES=	textproc graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	SVG
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org

PERL_CONFIGURE=	yes
PLIST_SUB=	EXAMPLESDIR="share/examples/${PORTNAME}"

MAN3=		SVG.3 SVG::DOM.3 SVG::Element.3 SVG::Manual.3 SVG::XML.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-patch:
	@${FIND} ${WRKSRC} \( -name "*.p[lm]" -or -name "*.cgi" \
		-or -name "*.pod" \)|xargs ${PERL} -pi -e 's/\x0d//g;'

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
