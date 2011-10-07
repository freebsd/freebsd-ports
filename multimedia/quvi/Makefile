# New ports collection makefile for:	quvi
# Date created:		2 February 2010
# Whom:			Toni Gundogdu <legatvs@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	quvi
PORTVERSION=	0.4.0
CATEGORIES=	multimedia devel
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION:R}/${PORTNAME}/ \
		GOOGLE_CODE

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Command line tool for parsing flash media stream URLs

LICENSE=	GPLv3

BUILD_DEPENDS=	libquvi>=${PORTVERSION}:${PORTSDIR}/multimedia/libquvi
LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	libquvi>=${PORTVERSION}:${PORTSDIR}/multimedia/libquvi

GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig
USE_XZ=		yes

MAN1=		quvi.1
PLIST_FILES=	bin/quvi

.include <bsd.port.mk>
