# Created by: shurd@FreeBSD.org
# $FreeBSD$

PORTNAME=	simsmith
PORTVERSION=	9.9
PORTREVISION=	1
CATEGORIES=	science hamradio
MASTER_SITES=	http://ae6ty.com/Smith_Charts_files/ \
		LOCAL/shurd
DISTNAME=	SimSmith9p9
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Java-based Smith Chart program

USE_JAVA=	yes
JAVA_RUN=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${DISTNAME}${EXTRACT_SUFX} \
		bin/${PORTNAME}
SUB_FILES=	simsmith
SUB_LIST+=	DISTNAME=${DISTNAME}
NO_BUILD=	yes

do-install:
	@${INSTALL_DATA} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${STAGEDIR}${JAVAJARDIR}
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
