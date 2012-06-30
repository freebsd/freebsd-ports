# New ports collection makefile for:	p5-openxpki-client-scep
# Date created:				03 Oct 2006
# Whom:					svysh
#
# $FreeBSD$
#

PORTNAME=	openxpki-client-scep
PORTVERSION=	0.9.1313
CATEGORIES=	security perl5
MASTER_SITES=	SF/openxpki/openxpki/0.9.1300
PKGNAMEPREFIX=	p5-
DISTNAME=	OpenXPKI-Client-SCEP-${PORTVERSION}
DIST_SUBDIR=	openxpki

MAINTAINER=	svysh@pn.sinp.msu.ru
COMMENT=	Client for SCEP requests to openxpki server

BUILD_DEPENDS=	\
	p5-Config-Std>=0:${PORTSDIR}/devel/p5-Config-Std \
	p5-openxpki-client>=0:${PORTSDIR}/security/p5-openxpki-client \
	p5-NetAddr-IP>=0:${PORTSDIR}/net-mgmt/p5-NetAddr-IP
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=	OpenXPKI::Client::SCEP.3
USE_GMAKE=	yes
PERL_CONFIGURE=	yes

.include <bsd.port.mk>
