# New ports collection makefile for:	squashfs-tools
# Date created:		2010-04-21
# Whom:			Ashish SHUKLA <wahjava@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	squashfs-tools
PORTVERSION=	4.0
CATEGORIES=	sysutils
MASTER_SITES=	SF/squashfs/squashfs/${DISTNAME}/
DISTNAME=	squashfs${PORTVERSION}

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Set of tools to manipulate squashfs images

PLIST_FILES=	bin/mksquashfs \
		bin/unsquashfs

.ifndef NOPORTDOCS
PORTDOCS=	ACKNOWLEDGEMENTS CHANGES COPYING \
		PERFORMANCE.README README README-4.0
.endif

post-patch:
	@${REINPLACE_CMD} -e "s:%%PREFIX%%:${PREFIX}:g" \
			${WRKSRC}/squashfs-tools/Makefile

do-build:
	@${MAKE} -C ${WRKSRC}/squashfs-tools

do-install:
	@${MAKE} -C ${WRKSRC}/squashfs-tools ${INSTALL}
.ifndef NOPORTDOCS
	@${MKDIR} ${DOCSDIR}
	@for i in ${PORTDOCS}; do ${INSTALL_DATA} ${WRKSRC}/$$i ${DOCSDIR}; done
.endif

.include <bsd.port.mk>
