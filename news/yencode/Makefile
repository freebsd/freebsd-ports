# ex:ts=8
# Ports collection makefile for:	yencode
# Date created:			Mar 24, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	yencode
PORTVERSION=	0.46
PORTREVISION=	3
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free (GPL) encoder and decoder for the yEnc Usenet file format

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old

USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=	ydecode.1 yencode.1 ypost.1
MAN5=	ypostrc.5

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
