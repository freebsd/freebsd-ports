# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	OQTEncoder
PORTVERSION=	0.1
PORTREVISION=	6
CATEGORIES=	multimedia
MASTER_SITES=	SF/openquicktime/OpenQuicktime%20v1/1.0b
DISTNAME=	${PORTNAME:tl}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple encoder using OpenQuicktime (TM)

LIB_DEPENDS=	libopenquicktime.so:multimedia/openquicktime

USES=		localbase tar:tgz
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/oqtencoder
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${TR} -d '\r' < ${WRKSRC}/readme > ${WRKSRC}/README
	@${REINPLACE_CMD} -e 's|gcc -g|${CC}|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME:tl} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
