# Created by: Lars Engels <lme@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flyback
PORTVERSION=	0.4.0
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	lme@FreeBSD.org
COMMENT=	A backup frontend like Apple's Time Machine

RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PYTHON=	yes
USE_GNOME=	pygtk2 pygnome2 libglade2

NO_STAGE=	yes
.include <bsd.port.pre.mk>

SUB_FILES=	flyback.sh

do-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/GPL.txt ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/viewer.glade ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/flyback.sh ${PREFIX}/bin/flyback

.include <bsd.port.post.mk>
