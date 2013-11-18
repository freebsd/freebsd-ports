# Created by: Anes Mukhametov <anes@anes.su>
# $FreeBSD$

PORTNAME=	Catalyst-Action-Serialize-XML-Hash-LX
PORTVERSION=	0.06
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	anes@anes.su
COMMENT=	XML::Hash::LX serializer for Catalyst::Action::Serialize

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Catalyst-Runtime>=0:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-XML-Hash-LX>=0.06:${PORTSDIR}/textproc/p5-XML-Hash-LX
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-lib-abs>=0.90:${PORTSDIR}/devel/p5-lib-abs

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
