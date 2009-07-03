# New ports collection makefile for:	p5-HTML-Element-Library
# Date created:				2007/02/14
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	HTML-Element-Library
PORTVERSION=	3.53
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	HTML::Element convenience functions

BUILD_DEPENDS=	p5-Array-Group>=0:${PORTSDIR}/devel/p5-Array-Group \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-List-Rotation-Cycle>=0:${PORTSDIR}/devel/p5-List-Rotation-Cycle \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Scalar-Listify>=0:${PORTSDIR}/devel/p5-Scalar-Listify \
		p5-HTML-PrettyPrinter>=0:${PORTSDIR}/www/p5-HTML-PrettyPrinter \
		p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	HTML::Element::Library.3 HTML::Element::Library::Changes.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

post-extract:
	@${CP} ${WRKSRC}/Changes ${WRKSRC}/CHANGES

.include <bsd.port.post.mk>
