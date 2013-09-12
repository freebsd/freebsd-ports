# Created by: Sergei Vyshenski <svysh@pn.sinp.msu.ru>
# $FreeBSD$

PORTNAME=	openxpki-i18n
PORTVERSION=	0.9.1395
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	SF/openxpki/openxpki/0.9.1300
PKGNAMEPREFIX=	p5-
DIST_SUBDIR=	openxpki

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Perl based trustcenter software for PKI: i18n tools

BUILD_DEPENDS=	\
	p5-openxpki>=0:${PORTSDIR}/security/p5-openxpki
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gettext gmake perl5
### We can not go WITHOUT_NLS. Internationalization is needed
### even to use English language.
ALL_TARGET=	default

.include <bsd.port.mk>
