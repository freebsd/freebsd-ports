# New ports collection makefile for:   bcwipe
# Date created:                                Mar 4, 2001
# Whom:                                        crow
#
# $FreeBSD$
#

PORTNAME=	bcwipe
PORTVERSION=	1.2.3
CATEGORIES=	security
MASTER_SITES=	http://www.jetico.com/linux/ \
		http://www.underworld.hu/~crow/distfiles/
DISTNAME=	BCWipe-${PORTVERSION:S/./-/g:S/-/./}

MAINTAINER=	crow@nektor.hu
COMMENT=	BCWipe securely erase data from magnetic and solid-state memory

NO_CDROM=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		bcwipe.1
PLIST_FILES=	bin/bcwipe

post-patch:
	@${REINPLACE_CMD} -e "s,^CFLAGS,#CFLAGS,g" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s,fprintf(stderr\,string),fprintf(stderr\,\"%s\"\,string),g" ${WRKSRC}/wipe.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bcwipe ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/bcwipe.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
