# New ports collection makefile for:	fspclient
# Date created:		7 Nov 1994
# Whom:			ache
#
# $FreeBSD$
#

PORTNAME=	fspclient
PORTVERSION=	0.91.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A ftp-like client for the FSP service

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		fsp.1
PLIST_FILES=	bin/fsp

post-patch:
	@${REINPLACE_CMD} -e 's|<getopt\.h>|<unistd.h>|g' ${WRKSRC}/bsd/ls.c

.include <bsd.port.mk>
