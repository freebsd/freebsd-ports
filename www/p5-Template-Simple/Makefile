# Created by: Ken McGlothlen <ken.mcglothlen@gmail.com>
# $FreeBSD$

PORTNAME=	Template-Simple
PORTVERSION=	0.06
CATEGORIES=	www textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ken.mcglothlen@gmail.com
COMMENT=	Fast templating module

LICENSE=	ART20

BUILD_DEPENDS=	p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Template::Simple.3

NO_STAGE=	yes
.include <bsd.port.mk>
