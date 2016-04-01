# Created by: Cheng-Lung Sung <clsung@dragon2.net>
# $FreeBSD$

PORTNAME=	XML-Smart
PORTVERSION=	1.79
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TMHARISH
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Smart, easy and powerful way to access/create XML files/data

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Object-MultiType>=0.03:devel/p5-Object-MultiType \
		p5-XML-XPath>=0:textproc/p5-XML-XPath
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Data-Dump>=0:devel/p5-Data-Dump \
		p5-Devel-Cycle>=0:devel/p5-Devel-Cycle

USES=		perl5
USE_PERL5=	configure

PORTDOCS=	Changes README

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."

.include <bsd.port.mk>
