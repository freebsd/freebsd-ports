# New ports collection makefile for:	glload
# Version required:		0.4.0
# Date created:			04 Dec 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.4 1998/12/08 16:07:34 vanilla Exp $
#

DISTNAME=	glload-0.4.0
CATEGORIES=	sysutils
MASTER_SITES=	http://glload.netpedia.net/source/
		http://www.freebsd.org/~vanilla/

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=	MesaGL.14:${PORTSDIR}/graphics/Mesa3

USE_X_PREFIX=	yes
MAKEFILE=	Makefile.FreeBSD
ALL_TARGET=	glload

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/glload ${PREFIX}/bin

.include <bsd.port.mk>
