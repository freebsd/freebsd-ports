# New ports collection makefile for:	p5-HTML-Element-Library
# Date created:				2007/02/14
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	HTML-Element-Library
PORTVERSION=	5.112.170
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	HTML::Element convenience functions

BUILD_DEPENDS=	p5-Array-Group>=0:${PORTSDIR}/devel/p5-Array-Group \
		p5-Data-Rmap>=0:${PORTSDIR}/devel/p5-Data-Rmap \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-HTML-FillInForm>=0:${PORTSDIR}/www/p5-HTML-FillInForm \
		p5-HTML-PrettyPrinter>=0:${PORTSDIR}/www/p5-HTML-PrettyPrinter \
		p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-List-Rotation-Cycle>=0:${PORTSDIR}/devel/p5-List-Rotation-Cycle \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Scalar-Listify>=0:${PORTSDIR}/devel/p5-Scalar-Listify
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTML::Element::Library::Changes.3 \
		HTML::Element::Library.3

post-extract:
	@cd ${WRKSRC} && pod2text lib/HTML/Element/Library.pm > README
	@cd ${WRKSRC} && pod2text lib/HTML/Element/Library/Changes.pod > CHANGES

.include <bsd.port.mk>
