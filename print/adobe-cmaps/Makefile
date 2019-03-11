# Created by: KATO Tsuguru <tkato@prontomail.com>
# $FreeBSD$

PORTNAME=	adobe-cmaps
PORTVERSION=	20051217
PORTREVISION=	4
CATEGORIES=	print
MASTER_SITES=	LOCAL/hrs/adobe
DISTFILES=	ac15.tar.gz ag15.tar.gz \
		ai0.tar.gz aj16.tar.gz \
		aj20.tar.gz ak12.tar.gz rksj-cmaps.tar.gz
DIST_SUBDIR=	adobe

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Adobe CMap collection

USES=		fonts
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
INSTDIRS=	ac15 ag15 ai0 aj16 aj20 ak12 rksj-cmaps
FONTSDIR=	${PREFIX}/share/fonts/${PORTNAME}

post-extract:
	${RM} ${WRKSRC}/ag15/.nfsFA55

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC} && \
		${TAR} cf - ${INSTDIRS} | \
		(cd ${STAGEDIR}${FONTSDIR} && ${TAR} xf - )

.include <bsd.port.mk>
