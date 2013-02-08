# Created by: Cheng-Lung Sung <clsung@dragon2.net>
# $FreeBSD$

PORTNAME=	XML-Smart
PORTVERSION=	1.75
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A Smart, easy and powerful way to access/create XML files/data

BUILD_DEPENDS=	p5-Object-MultiType>=0.03:${PORTSDIR}/devel/p5-Object-MultiType \
		p5-XML-XPath>=0:${PORTSDIR}/textproc/p5-XML-XPath
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Devel-Cycle>=0:${PORTSDIR}/devel/p5-Devel-Cycle \
		p5-Data-Dump>=0:${PORTSDIR}/devel/p5-Data-Dump

PERL_CONFIGURE=	YES

MAN3=		XML::Smart.3 \
		XML::Smart::DTD.3 \
		XML::Smart::FAQ.3 \
		XML::Smart::Shared.3 \
		XML::Smart::Tutorial.3

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
