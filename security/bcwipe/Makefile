# New ports collection makefile for:   bcwipe
# Date created:                                Mar 4, 2001
# Whom:                                        crow
#
# $FreeBSD$
#

PORTNAME=	bcwipe
PORTVERSION=	1.5.3
CATEGORIES=	security
MASTER_SITES=	http://www.jetico.com/linux/ \
		http://www.bsdberlin.org/~dako/distfiles/security/
DISTNAME=	BCWipe-${PORTVERSION:S/./-/g:S/-/./}

MAINTAINER=	dako@bsdberlin.org
COMMENT=	BCWipe securely erases data from magnetic and solid-state memory

NO_CDROM=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
CFLAGS+=	-DOS_FreeBSD

MAN1=		bcwipe.1
PLIST_FILES=	bin/bcwipe

post-patch:
	@${REINPLACE_CMD} -e "s,^CFLAGS,#CFLAGS,g" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s,fprintf(stderr\,string),fprintf(stderr\,\"%s\"\,string),g" ${WRKSRC}/wipe.c
	@${REINPLACE_CMD} -e "s,if (NULL == mktemp(result)),if (mkstemp(result) == -1),g" ${WRKSRC}/wipe.c
	@${REINPLACE_CMD} -e "s,mktemp,mkstemp,g" ${WRKSRC}/wipe.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bcwipe ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/bcwipe.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
