# ex:ts=8
# Ports collection makefile for:	p5-Pod-Tree
# Date created:			Aug 10, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Pod-Tree
PORTVERSION=	1.11
CATEGORIES=	textproc devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Pod
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create a static syntax tree for a POD

BUILD_DEPENDS=	${SITE_PERL}/HTML/Stream.pm:${PORTSDIR}/www/p5-HTML-Stream \
		${SITE_PERL}/Pod/Escapes.pm:${PORTSDIR}/textproc/p5-Pod-Escapes
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		perl2html.1 pods2html.1
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

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 500600
PLIST_SUB+=	POD2HTML="@comment "
.else
MAN1+=		pod2html.1
PLIST_SUB+=	POD2HTML=""
.endif

post-patch:
.if ${PERL_LEVEL} >= 500600
	${REINPLACE_CMD} -e 's/pod2html //g' ${WRKSRC}/Makefile.PL
.endif

.include <bsd.port.post.mk>
