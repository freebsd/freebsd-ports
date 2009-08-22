# New ports collection makefile for:	oqtplayer
# Date created:				Mon Sep 24 16:26:33 BRT 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	OQTEncoder
PORTVERSION=	0.1
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	SF/openquicktime/OpenQuicktime%20v1/1.0b
DISTNAME=	${PORTNAME:L}-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple encoder using OpenQuicktime (TM)

LIB_DEPENDS=	openquicktime.0:${PORTSDIR}/multimedia/openquicktime

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAKE_ARGS=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/oqtencoder

.if !defined(NOPORTDOCS)
PORTDOCS=	README
.endif

post-patch:
	@${TR} -d '\r' < ${WRKSRC}/readme > ${WRKSRC}/README
	@${REINPLACE_CMD} -e 's|gcc -g|${CC}|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME:L} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
