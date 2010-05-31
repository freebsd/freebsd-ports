# New ports collection makefile for:	p5-openxpki-i18n
# Date created:				03 Oct 2006
# Whom:					svysh
#
# $FreeBSD$
#

PORTNAME=	openxpki-i18n
PORTVERSION=	0.9.1395
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	SF/openxpki/openxpki/0.9.1300
PKGNAMEPREFIX=	p5-
DIST_SUBDIR=	openxpki

MAINTAINER=	svysh@pn.sinp.msu.ru
COMMENT=	Perl based trustcenter software for PKI: i18n tools

BUILD_DEPENDS=	\
	${SITE_PERL}/${PERL_ARCH}/OpenXPKI.pm:${PORTSDIR}/security/p5-openxpki
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	yes
USE_GETTEXT=	yes
### We can not go WITHOUT_NLS. Internationalization is needed
### even to use English language.
USE_GMAKE=	yes
ALL_TARGET=	default

.include <bsd.port.mk>
