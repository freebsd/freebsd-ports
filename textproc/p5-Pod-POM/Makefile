# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Pod-POM
PORTVERSION=	0.28
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	POD Object Model

BUILD_DEPENDS=	p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=		podlint.1 pom2.1 pomdump.1
MAN3=		Pod::POM.3 \
		Pod::POM::Constants.3 \
		Pod::POM::Node.3 \
		Pod::POM::Node::Begin.3 \
		Pod::POM::Node::Code.3 \
		Pod::POM::Node::Content.3 \
		Pod::POM::Node::For.3 \
		Pod::POM::Node::Head1.3 \
		Pod::POM::Node::Head2.3 \
		Pod::POM::Node::Head3.3 \
		Pod::POM::Node::Head4.3 \
		Pod::POM::Node::Item.3 \
		Pod::POM::Node::Over.3 \
		Pod::POM::Node::Pod.3 \
		Pod::POM::Node::Sequence.3 \
		Pod::POM::Node::Text.3 \
		Pod::POM::Node::Verbatim.3 \
		Pod::POM::Nodes.3 \
		Pod::POM::View.3 \
		Pod::POM::View::HTML.3 \
		Pod::POM::View::Pod.3 \
		Pod::POM::View::Text.3

.include <bsd.port.mk>
