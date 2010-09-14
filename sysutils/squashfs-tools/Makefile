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

MAKE_JOBS_SAFE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/squashfs-tools

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../COPYING

.ifndef NOPORTDOCS
PORTDOCS=	ACKNOWLEDGEMENTS CHANGES COPYING \
		PERFORMANCE.README README README-4.0
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|g" \
		${WRKSRC}/Makefile

.ifndef NOPORTDOCS
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC:H}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
