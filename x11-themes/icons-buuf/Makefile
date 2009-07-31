# New ports collection makefile for:	icons-buuf
# Date created:		2006-10-09
# Whom:			Phillip Neumann <pneumann@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	icons-buuf
PORTVERSION=	1.6r2
PORTREVISION=	3
CATEGORIES=	x11-themes
MASTER_SITES=	http://ic1.deviantart.com/fs12/f/2006/266/9/0/
DISTNAME=	Buuf_1.6-r2
EXTRACT_SUFX=	_tar_bz2

MAINTAINER=	pneumann@gmail.com
COMMENT=	A cool set of icons for the most common usage

NO_BUILD=	yes
USE_BZIP2=	yes
WRKSRC=	${WRKDIR}/Buuf
USE_GNOME=	gtk20
INSTALLS_ICONS=	yes

do-install:
	@${RM} ${WRKSRC}/128x128/status/sunny.png
	@${MKDIR} ${PREFIX}/share/icons/Buuf
	@${CP} -rip ${WRKSRC} ${PREFIX}/share/icons/

.include <bsd.port.mk>
