# Created by: Juergen Lock <nox@jelal.kn-bremen.de>
# $FreeBSD$

PORTNAME=	projectx
PORTVERSION=	0.91.0
CATEGORIES=	multimedia java
MASTER_SITES=	SF/project-x/project-x/ProjectX_${PORTVERSION}.00
DISTNAME=	ProjectX_${PORTVERSION}
DISTFILES=	ProjectX_${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nox@FreeBSD.org
COMMENT=	DVB (mpeg) cutting/demux tool

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USES=		zip:infozip
USE_JAVA=	yes
JAVA_VERSION=	1.6+

SUB_FILES=	project-x.sh
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
WRKSRC=		${WRKDIR}/Project-X_${PORTVERSION}
EXTRACT_BEFORE_ARGS+=	-aq

do-configure:
	${SED} -e "s|^javac|${JAVAC}|" ${WRKSRC}/build.sh >${WRKSRC}/build-fbsd.sh

do-build:
	cd ${WRKSRC} && ${MKDIR} build && ${SH} build-fbsd.sh

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/lib
	${INSTALL_DATA} ${WRKSRC}/ProjectX.jar \
		${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/commons-net-1.3.0.jar \
		${STAGEDIR}${DATADIR}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/jakarta-oro-2.0.8.jar \
		${STAGEDIR}${DATADIR}/lib
	${MKDIR} ${STAGEDIR}${DATADIR}/htmls/images \
		${STAGEDIR}${DATADIR}/htmls/de
	${INSTALL_DATA} ${WRKSRC}/*.txt \
		${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/htmls/*.html \
		${STAGEDIR}${DATADIR}/htmls
	${INSTALL_DATA} ${WRKSRC}/htmls/de/*.html \
		${STAGEDIR}${DATADIR}/htmls/de
	${INSTALL_DATA} ${WRKSRC}/htmls/images/* \
		${STAGEDIR}${DATADIR}/htmls/images
	${INSTALL_SCRIPT} ${WRKDIR}/project-x.sh \
		${STAGEDIR}${PREFIX}/bin/project-x

.include <bsd.port.mk>
