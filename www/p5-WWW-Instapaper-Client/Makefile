# Created by: TERAMOTO Masahiro <markun@onohara.to>
# $FreeBSD$

PORTNAME=	WWW-Instapaper-Client
PORTVERSION=	0.901
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	An implementation of the Instapaper client API

BUILD_DEPENDS=	p5-Class-Base>=0:${PORTSDIR}/devel/p5-Class-Base \
		p5-Crypt-SSLeay>=0:${PORTSDIR}/security/p5-Crypt-SSLeay \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=		WWW::Instapaper::Client.3

NO_STAGE=	yes
.include <bsd.port.mk>
