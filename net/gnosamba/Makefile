# New ports collection makefile for:	gnosamba
# Date created:				4 November 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	gnosamba
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/g/gnosamba
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Samba configuration tool for X Window System

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.orig

USE_X_PREFIX=	yes
USE_GNOME=	gnomelibs
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/src/*.c

.include <bsd.port.mk>
