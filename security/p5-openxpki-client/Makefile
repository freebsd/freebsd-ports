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

USES=		perl5 gmake
USE_PERL5=	configure

.include <bsd.port.mk>
