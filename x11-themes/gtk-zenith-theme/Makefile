# New ports collection makefile for:	gtk-zenith-theme
# Date Created:				23 June 2001
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gtk-zenith-theme
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_THEMES}
MASTER_SITE_SUBDIR=	zenith
DISTNAME=	zenith-1.2

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	The Zenith GTK theme engine

WRKSRC=		${WRKDIR}/zenith-1.0

USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/ltconfig

.include <bsd.port.mk>
