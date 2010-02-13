# New ports collection makefile for:	quvi
# Date created:		2 February 2010
# Whom:			Toni Gundogdu <legatvs@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	quvi
PORTVERSION=	0.1.1
CATEGORIES=	multimedia devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	legatvs@gmail.com
COMMENT=	Query video library for Youtube like websites

LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl \
		pcre.0:${PORTSDIR}/devel/pcre

USE_LDCONFIG=	yes
SHLIB_VER=	0

MAKE_ENV=	SHLIB_VER="${SHLIB_VER}"
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"

MAN1=		quvi.1

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig
USE_ICONV=	yes

OPTIONS=	SMUT "Enable adult website support" off

.include <bsd.port.pre.mk>

.if defined(WITH_SMUT)
CONFIGURE_ARGS+=--enable-smut
.endif

.include <bsd.port.post.mk>
