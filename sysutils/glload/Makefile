# New ports collection makefile for:	glload
# Version required:		0.4.0
# Date created:			04 Dec 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	glload-0.4.0
CATEGORIES=	sysutils
MASTER_SITES=	http://glload.netpedia.net/source/ \
		http://www.freebsd.org/~vanilla/

MAINTAINER=	vanilla@FreeBSD.org

LIB_DEPENDS=	MesaGL.14:${PORTSDIR}/graphics/Mesa3

USE_X_PREFIX=	yes
MAKEFILE=	Makefile.FreeBSD
ALL_TARGET=	glload

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/glload ${PREFIX}/bin

.include <bsd.port.mk>
