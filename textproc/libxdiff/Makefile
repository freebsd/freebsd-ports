# ex:ts=8
# Ports collection makefile for:	libxdiff
# Date created:			Jan 5, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libxdiff
PORTVERSION=	0.10
CATEGORIES=	textproc
MASTER_SITES=	http://www.xmailserver.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create file differences/patches to both binary and text files

WRKSRC=		${WRKDIR}/${PORTNAME}

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN3=		xdiff.3
PLIST_FILES=	include/xdiff.h lib/libxdiff.a

.include <bsd.port.mk>
