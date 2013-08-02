# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	XML-SAX-Machines
PORTVERSION=	0.42
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Manage collections of SAX processors

BUILD_DEPENDS=	p5-XML-SAX>=0:${PORTSDIR}/textproc/p5-XML-SAX \
		p5-XML-SAX-Writer>=0:${PORTSDIR}/textproc/p5-XML-SAX-Writer
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		XML::Filter::Distributor.3 XML::Filter::DocSplitter.3 \
		XML::Filter::Merger.3 XML::Filter::Tee.3 XML::SAX::ByRecord.3 \
		XML::SAX::EventMethodMaker.3 XML::SAX::Machine.3 \
		XML::SAX::Machines.3 XML::SAX::Machines::ConfigHelper.3 \
		XML::SAX::Manifold.3 XML::SAX::Pipeline.3 XML::SAX::Tap.3

regression-test: build
	${MAKE} -C ${WRKSRC} test

post-install:
.ifndef(NOPORTEXAMPLES)
		@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
		@${MKDIR} ${EXAMPLESDIR}
		${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
