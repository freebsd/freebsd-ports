# ex:ts=8
# Ports collection makefile for:	recmpeg
# Date created:			Mar 24, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	recmpeg
PORTVERSION=	1.0.5
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fame

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple video encoder

LIB_DEPENDS=	fame-0.9.0:${PORTSDIR}/multimedia/libfame

USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		recmpeg.1
PLIST_FILES=	bin/recmpeg

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
