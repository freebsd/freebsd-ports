# New ports collection makefile for:    wminfo
# Date created:         09 February 2004
# Whom:                 Thomas Kempka <t.kempka@web.de>
#
# $FreeBSD$
#

PORTNAME=	wminfo
PORTVERSION=	1.51
CATEGORIES=	misc windowmaker
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pav

MAINTAINER=	t.kempka@web.de
COMMENT=	Dockapp to run shell scripts and display the output

WRKSRC=		${WRKDIR}/${PORTNAME}/${PORTNAME}

USE_X_PREFIX=	yes
USE_XPM=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$$(LIBS)$$|& $$(OBJS)|g' \
		-e 's|/usr/X11R6|$$(X11BASE)|g' \
		-e 's|/share/include|/include|g' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wminfo ${PREFIX}/bin

.include <bsd.port.mk>
