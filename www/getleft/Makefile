# New ports collection makefile for:	getleft
# Date created:				2006-11-07
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	getleft
PORTVERSION=	1.2b2
PORTREVISION=	2
CATEGORIES=	www ftp
MASTER_SITES=	SF/${PORTNAME}down/${PORTNAME}-devel/${PORTVERSION}
DISTNAME=	Getleft-${PORTVERSION}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Web site downloader

RUN_DEPENDS=	${LOCALBASE}/lib/Tktable2.10/libTktable2.10.so:${PORTSDIR}/x11-toolkits/tktable \
		${LOCALBASE}/lib/libttkstub.a:${PORTSDIR}/x11-toolkits/tile

USE_TK=		84

# Avoid minus signs in versions.
PORTSCOUT=	limit:^[[:alnum:]]+(?!-)$

post-extract:
	@${RM} ${WRKSRC}/install.*

do-build:
	@(${ECHO_CMD} "#!${SH}"; ${ECHO_CMD} "cd ${DATADIR} || exit 1"; \
	  ${ECHO_CMD} 'exec ${WISH} Getleft.tcl "$$@"') > ${WRKDIR}/${PORTNAME}

do-install:
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/* ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
