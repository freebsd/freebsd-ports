# ex:ts=8
# Ports collection makefile for:	gss
# Date created:			Oct 19, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gss
PORTVERSION=	0.0.6
CATEGORIES=	security
MASTER_SITES=	http://josefsson.org/${PORTNAME}/releases/ \
		${MASTER_SITE_GNU_ALPHA}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Generic Security Service Library

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv \
		intl.5:${PORTSDIR}/devel/gettext

USE_GNOME=	gnomehack
GNU_CONFIGURE=	yes

INSTALLS_SHLIB=	yes

INFO=	gss

.include <bsd.port.mk>
