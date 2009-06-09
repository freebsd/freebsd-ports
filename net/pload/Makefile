# New ports collection makefile for:	pload
# Date created:				22 Septemper 2004
# Whom:					J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	pload
PORTVERSION=	0.9.5
PORTREVISION=	2
CATEGORIES=	net sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://opal.com/freebsd/ports/net/pload/
MASTER_SITE_SUBDIR=	pav

MAINTAINER=	fbsd@opal.com
COMMENT=	An X11 program to display network traffic graphs

USE_IMAKE=	yes
USE_XORG=	ice sm x11 xaw xext xmu xpm xt
HAS_CONFIGURE=	yes

MAN1=		pload.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/pload

.include <bsd.port.mk>
