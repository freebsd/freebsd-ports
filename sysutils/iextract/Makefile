# New ports collection makefile for:	IExtract
# Date created:		19 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IExtract
PORTVERSION=	0.9.20
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	corky1951@comcast.net
COMMENT=	Extract meta-information from files

LIB_DEPENDS=	YGP.0:${PORTSDIR}/devel/libYGP

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE} --disable-rpath

.include <bsd.port.mk>
