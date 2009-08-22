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
	${SITE_PERL}/Config/Std.pm:${PORTSDIR}/devel/p5-Config-Std \
	${SITE_PERL}/OpenXPKI/Client.pm:${PORTSDIR}/security/p5-openxpki-client \
	${SITE_PERL}/${PERL_ARCH}/NetAddr/IP.pm:${PORTSDIR}/net-mgmt/p5-NetAddr-IP
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	OpenXPKI::Client::SCEP.3
USE_GMAKE=	yes
PERL_CONFIGURE=	yes

.include <bsd.port.mk>
