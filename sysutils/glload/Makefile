# New ports collection makefile for:	glload
# Version required:		0.3.3
# Date created:			04 Dec 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.1.1.1 1998/12/06 14:06:05 vanilla Exp $
#

DISTNAME=	glload-0.3.3
CATEGORIES=	sysutils
MASTER_SITES=	http://student.ex.ba-heidenheim.de/gload/

MAINTAINER=	vanilla@FreeBSD.ORG

BROKEN= 'the single MASTER_SITE gives: "Alert!: HTTP/1.1 404 File Not Found"'

LIB_DEPENDS=	MesaGL.14:${PORTSDIR}/graphics/Mesa3

USE_X_PREFIX=	yes
MAKEFILE=	Makefile.FreeBSD
ALL_TARGET=	glload

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/glload ${PREFIX}/bin

.include <bsd.port.mk>
