# Created by: kevit
# $FreeBSD$

PORTNAME=	Template-Plugin-XML-Escape
PORTVERSION=	0.02
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	simarg@gmail.com
COMMENT=	Escape variables to suit being placed into XML

BUILD_DEPENDS=	p5-Template-Toolkit>=2.20:${PORTSDIR}/www/p5-Template-Toolkit
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
MAN3=		Template::Plugin::XML::Escape.3

NO_STAGE=	yes
.include <bsd.port.mk>
