# ex:ts=8
# Ports collection makefile for:	yencode
# Date created:			Mar 24, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	yencode
PORTVERSION=	0.46
PORTREVISION=	2
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free (GPL) encoder and decoder for the yEnc Usenet file format

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

USE_GETOPT_LONG=yes
GNU_CONFIGURE=	yes
CPPFLAGS=	${CXXFLAGS} -I${LOCALBASE}/include
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LIBS="-L${LOCALBASE}/lib"

MAN1=	ydecode.1 yencode.1 ypost.1
MAN5=	ypostrc.5

.include <bsd.port.mk>
