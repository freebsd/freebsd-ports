# Created by: Sergei Vyshenski <svysh@pn.sinp.msu.ru>
# $FreeBSD$

PORTNAME=	openxpki-client-scep
PORTVERSION=	0.9.1313
CATEGORIES=	security perl5
MASTER_SITES=	SF/openxpki/openxpki/0.9.1300
PKGNAMEPREFIX=	p5-
DISTNAME=	OpenXPKI-Client-SCEP-${PORTVERSION}
DIST_SUBDIR=	openxpki

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Client for SCEP requests to openxpki server

BUILD_DEPENDS=	\
	p5-Config-Std>=0:${PORTSDIR}/devel/p5-Config-Std \
	p5-openxpki-client>=0:${PORTSDIR}/security/p5-openxpki-client \
	p5-NetAddr-IP>=0:${PORTSDIR}/net-mgmt/p5-NetAddr-IP
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 gmake
USE_PERL5=	configure

.include <bsd.port.mk>
