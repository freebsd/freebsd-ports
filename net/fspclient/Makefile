# New ports collection makefile for:	fspclient
# Date created:		7 Nov 1994
# Whom:			ache
#
# $FreeBSD$
#

PORTNAME=	fspclient
PORTVERSION=	0.0.9
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A ftp-like client for the fsp service

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETOPT_LONG=	yes

CFLAGS+=	-I${LOCALBASE}/include

MAN1=		fsp.1
PLIST_FILES=	bin/fsp

.include <bsd.port.mk>
