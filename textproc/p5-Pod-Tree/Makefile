# ex:ts=8
# Ports collection makefile for:	p5-Pod-Tree
# Date created:			Aug 10, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Pod-Tree
PORTVERSION=	1.17
CATEGORIES=	textproc devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Create a static syntax tree for a POD

RUN_DEPENDS=	p5-HTML-Stream>=1.49:${PORTSDIR}/www/p5-HTML-Stream \
		p5-IO-String>=1:${PORTSDIR}/devel/p5-IO-String \
		p5-Text-Template>=1:${PORTSDIR}/textproc/p5-Text-Template
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		mod2html.1 perl2html.1 pods2html.1 podtree2html.1
MAN3=		Pod::Tree.3 \
		Pod::Tree::HTML.3 \
		Pod::Tree::Node.3 \
		Pod::Tree::PerlBin.3 \
		Pod::Tree::PerlDist.3 \
		Pod::Tree::PerlFunc.3 \
		Pod::Tree::PerlLib.3 \
		Pod::Tree::PerlMap.3 \
		Pod::Tree::PerlPod.3 \
		Pod::Tree::PerlTop.3 \
		Pod::Tree::Pod.3

# conflict with pod2html in perl 5.6 or above
post-patch:
	${REINPLACE_CMD} -e 's/pod2html //g' ${WRKSRC}/Makefile.PL
	${REINPLACE_CMD} -e '/pod2html/d' ${WRKSRC}/MANIFEST
	${RM} ${WRKSRC}/t/pod2html.t

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-Pod-Escapes>=1.02:${PORTSDIR}/textproc/p5-Pod-Escapes
.endif

.include <bsd.port.post.mk>
