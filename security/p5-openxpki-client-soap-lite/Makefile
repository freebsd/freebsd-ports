# New ports collection makefile for:	p5-openxpki-client-soap-lite
# Date created:				03 Oct 2006
# Whom:					svysh
#
# $FreeBSD$
#

PORTNAME=	openxpki-client-soap-lite
PORTVERSION=	0.9.651
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	openxpki
PKGNAMEPREFIX=	p5-
DISTNAME=	OpenXPKI-Client-SOAP-Lite-${PORTVERSION}
DIST_SUBDIR=	openxpki

MAINTAINER=	svysh@cryptocom.ru
COMMENT=	SOAP-Lite toolkit for openxpki

BUILD_DEPENDS=	\
	${SITE_PERL}/OpenXPKI/Client.pm:${PORTSDIR}/security/p5-openxpki-client \
	${SITE_PERL}/SOAP/Lite.pm:${PORTSDIR}/net/p5-SOAP-Lite
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	OpenXPKI::Client::SOAP::Lite.3
USE_PERL5=	yes
USE_GMAKE=	yes
PERL_CONFIGURE=	yes

.include <bsd.port.mk>
