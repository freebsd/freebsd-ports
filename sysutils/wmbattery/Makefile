# New ports collection makefile for:	wmbattery
# Date created:		18 Sep 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	wmbattery
PORTVERSION=	1.21
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://kitenet.net/programs/code/wmbattery/ \
		http://kitenet.net/programs/code/debian/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	pat@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--x-libraries=${X11BASE}/lib \
		--x-includes=${X11BASE}/include

MAN1=		wmbattery.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in README TODO
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
