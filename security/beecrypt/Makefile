# ex:ts=8
# New ports collection makefile for:	beecrypt
# Date created:			Mar 4, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	beecrypt
PORTVERSION=	4.1.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	BeeCrypt is an open source cryptography library

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|-pthread|${PTHREAD_LIBS}|g" ${WRKSRC}/configure

.include <bsd.port.mk>
