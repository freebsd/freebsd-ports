# New ports collection makefile for:	wmbattery
# Version required:	1.11
# Date created:		18 Sep 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	wmbattery
PKGNAME=	${DISTNAME}-1.11
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://kitenet.net/programs/code/wmbattery/

MAINTAINER=	andrews@technologist.com

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes

USE_GMAKE=	YES
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
