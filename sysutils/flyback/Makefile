# Created by: Lars Engels <lme@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flyback
PORTVERSION=	0.4.0
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Backup frontend like Apple's Time Machine

RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		python
USE_GNOME=	pygtk2 pygnome2 libglade2

SUB_FILES=	flyback.sh

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/GPL.txt ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/viewer.glade ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/flyback.sh ${STAGEDIR}${PREFIX}/bin/flyback

.include <bsd.port.mk>
