# New ports collection makefile for:	p5-HTML-Element-Library
# Date created:				2007/02/14
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	HTML-Element-Library
PORTVERSION=	4.2.b
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	HTML::Element convenience functions

RUN_DEPENDS=	p5-Array-Group>=1:${PORTSDIR}/devel/p5-Array-Group \
		p5-File-Slurp>=9999.06:${PORTSDIR}/devel/p5-File-Slurp \
		p5-HTML-FillInForm>=0:${PORTSDIR}/www/p5-HTML-FillInForm \
		p5-HTML-PrettyPrinter>=0.03:${PORTSDIR}/www/p5-HTML-PrettyPrinter \
		p5-HTML-Tree>=3.19:${PORTSDIR}/www/p5-HTML-Tree \
		p5-List-MoreUtils>=0.09:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-List-Rotation-Cycle>=1.003:${PORTSDIR}/devel/p5-List-Rotation-Cycle \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Params-Validate>=0.8:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Scalar-Listify>=0.02:${PORTSDIR}/devel/p5-Scalar-Listify
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTML::Element::Library::Changes.3 \
		HTML::Element::Library.3

post-extract:
	@cd ${WRKSRC} && pod2text lib/HTML/Element/Library.pm > README
	@cd ${WRKSRC} && pod2text lib/HTML/Element/Library/Changes.pod > CHANGES

.include <bsd.port.mk>
