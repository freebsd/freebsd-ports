# New ports collection makefile for:	mmosaic
# Date created:				2000-12-26
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	mmosaic
PORTVERSION=	3.7.2
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.enst.fr/pub/mbone/mMosaic/ \
		ftp://ftp.uni-koeln.de/net/inet/WWW/mosaic/unix/ \
		ftp://ftp.netsw.org/netsw/InfoSys/WWW/ClientSide/Browser/mosaic/ \
		ftp://ftp.icm.edu.pl/vol/rzm0/mMosaic/
DISTNAME=	mMosaic-${PORTVERSION}

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Web browser based on Mosaic, but with many modernizations

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

NO_CDROM="academic, research and internal business purposes only, without a fee"
NO_PACKAGE=	"must cause any work...derived...to be licensed as a whole...under...this License"
PLIST=		${WRKDIR}/pkg-plist
USE_MOTIF=	yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/mMosaic-src-${PORTVERSION}

post-patch:
.for ii in libhtmlw/HTML-PSformat.c libhtmlw/HTML.c libhtmlw/HTMLcolors.c \
 libmc/mc_obj.c libnut/list.c src/proxy-dialogs.c
	${MV} ${WRKSRC}/${ii} ${WRKSRC}/${ii}.orig
	${GREP} -v malloc.h ${WRKSRC}/${ii}.orig > ${WRKSRC}/${ii}
.endfor

pre-install:
	${ECHO_CMD} bin/mmosaic > ${PLIST}
	cd ${WRKSRC}/Copyrights; for i in `${FIND} * -type f`; do \
		${ECHO_CMD} share/doc/mmosaic/$${i} >> ${PLIST}; \
	done

do-install:
	${MKDIR} ${PREFIX}/share/doc/mmosaic/
	${INSTALL_DATA} ${WRKSRC}/Copyrights/* ${PREFIX}/share/doc/mmosaic/
#	${INSTALL_DATA} ${WRKSRC}/app-def/app-defaults.color ${PREFIX}/lib/X11/app-defaults/mMosaic
	${INSTALL_PROGRAM} ${WRKSRC}/src/mMosaic ${PREFIX}/bin/mmosaic

.include <bsd.port.mk>
