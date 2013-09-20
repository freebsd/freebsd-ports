# Created by: alepulver
# $FreeBSD$

PORTNAME=	getleft
PORTVERSION=	1.2
PORTEPOCH=	1
CATEGORIES=	www ftp
MASTER_SITES=	SF/${PORTNAME}down/${PORTNAME}-Stable/${PORTVERSION}
DISTNAME=	Getleft-v${PORTVERSION}

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Web site downloader

RUN_DEPENDS=	${LOCALBASE}/lib/Tktable2.10/libTktable2.10.so:${PORTSDIR}/x11-toolkits/tktable \
		${LOCALBASE}/lib/libttkstub.a:${PORTSDIR}/x11-toolkits/tile

USE_TK=		84+
PORTSCOUT=	ignore:1

NO_STAGE=	yes
do-build:
	@(${ECHO_CMD} "#!${SH}"; ${ECHO_CMD} "cd ${DATADIR} || exit 1"; \
	  ${ECHO_CMD} 'exec ${WISH} Getleft.tcl "$$@"') > ${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/Getleft.tcl ${DATADIR}
.for dir in Languages doc scripts images
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${DATADIR})
.endfor

.include <bsd.port.mk>
