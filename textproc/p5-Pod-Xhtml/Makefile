# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Pod-Xhtml
PORTVERSION=	1.61
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generate well-formed XHTML documents from POD format documentation

BUILD_DEPENDS=	p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Assertions>0:${PORTSDIR}/devel/p5-Test-Assertions

USES=		perl5
USE_PERL5=	configure

MAN1=		pod2xhtml.1
MAN3=		Pod::Hyperlink::BounceURL.3 Pod::Xhtml.3

.include <bsd.port.mk>
