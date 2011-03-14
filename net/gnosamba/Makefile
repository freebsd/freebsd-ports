# New ports collection makefile for:	gnosamba
# Date created:				4 November 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	gnosamba
PORTVERSION=	0.3.3
PORTREVISION=	7
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/g/gnosamba
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Samba configuration tool for X Window System

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.orig

PLIST_FILES=	bin/gnosamba
USE_GNOME=	gnomelibs
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/src/*.c

.include <bsd.port.mk>
