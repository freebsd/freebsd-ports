# New ports collection makefile for:	mmosaic
# Date created:				2000-12-26
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	mmosaic
PORTVERSION=	3.7.2
PORTREVISION?=	4
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.enst.fr/pub/mbone/mMosaic/ \
		ftp://ftp.uni-koeln.de/net/inet/WWW/mosaic/unix/ \
		ftp://ftp.netsw.org/infosys/www/clientside/browser/mosaic/
DISTNAME=	mMosaic-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web browser based on Mosaic, but with many modernizations

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

RESTRICTED=	"academic, research and internal business purposes only, without a fee"
PLIST=		${WRKDIR}/pkg-plist
USE_MOTIF=	yes
WRKSRC=		${WRKDIR}/mMosaic-src-${PORTVERSION}

post-patch:
.for ii in libhtmlw/HTML-PSformat.c libhtmlw/HTML.c libhtmlw/HTMLcolors.c \
 libmc/mc_obj.c libnut/list.c src/proxy-dialogs.c
	${MV} ${WRKSRC}/${ii} ${WRKSRC}/${ii}.orig
	${GREP} -v malloc.h ${WRKSRC}/${ii}.orig > ${WRKSRC}/${ii}
.endfor

pre-install:
	${ECHO_CMD} bin/mmosaic > ${PLIST}
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/Copyrights; for i in `${FIND} * -type f`; do \
		${ECHO_CMD} %%DOCSDIR%%/$${i} >> ${PLIST}; \
	done
	${ECHO_CMD} @dirrm %%DOCSDIR%% >> ${PLIST}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mMosaic ${PREFIX}/bin/mmosaic
#	${INSTALL_DATA} ${WRKSRC}/app-def/app-defaults.color ${PREFIX}/lib/X11/app-defaults/mMosaic
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Copyrights/* ${DOCSDIR}/
.endif

.include <bsd.port.mk>
