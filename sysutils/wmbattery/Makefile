# New ports collection makefile for:	wmbattery
# Date created:		18 Sep 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	wmbattery
PORTVERSION=	1.12
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://kitenet.net/programs/code/wmbattery/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_X_PREFIX=	yes

USE_GMAKE=	yes
MAKE_ENV=	PREFIX="${PREFIX}" INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}" INSTALL_MAN="${INSTALL_MAN}"
ALL_TARGET=	wmbattery
MAN1=		wmbattery.1

# install additional docs
.if !defined(NOPORTDOCS)
post-install:
.for i in COPYING INSTALL README TODO
	@${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/wmbattery
.endfor
.endif

.include <bsd.port.mk>
