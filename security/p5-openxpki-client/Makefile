# Created by: Sergei Vyshenski <svysh@pn.sinp.msu.ru>
# $FreeBSD$

PORTNAME=	openxpki-client
PORTVERSION=	0.9.1284
CATEGORIES=	security perl5
MASTER_SITES=	SF/openxpki/openxpki/0.9.1300
PKGNAMEPREFIX=	p5-
DISTNAME=	OpenXPKI-Client-${PORTVERSION}
DIST_SUBDIR=	openxpki

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Perl based trustcenter software for PKI: base class for actual clients

BUILD_DEPENDS=	\
	p5-openxpki>=0:${PORTSDIR}/security/p5-openxpki
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=	OpenXPKI::Client.3 \
	OpenXPKI::Client::API.3
USE_GMAKE=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
