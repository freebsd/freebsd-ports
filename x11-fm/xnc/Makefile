# New ports collection makefile for:	xnc
# Date created:		5 February 1999
# Whom:			Dima Sivachenko	<dima@chg.ru>
#
# $FreeBSD$
#

PORTNAME=	xnc
PORTVERSION=	4.4.7
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.xnc.dubna.su/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	demon@FreeBSD.org

# xnc will use the following programs if you have them installed.
#RUN_DEPENDS=	zip:${PORTSDIR}/archivers/zip		\
#		unzip:${PORTSDIR}/archivers/unzip	\
#		rpm:${PORTSDIR}/archivers/rpm		\
#		rar:${PORTSDIR}/archivers/rar		\
#		unarj:${PORTSDIR}/archivers/unarj	\
#		lha:${PORTSDIR}/archivers/lha
#.if !exists(/usr/bin/bzip2)
#RUN_DEPENDS+=	bzip2:${PORTSDIR}/archivers/bzip2
#.endif
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-pty=BSD
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		es.1 ives.1 vs.1 xjpegroot.1 xnc.1 xnlaunch.1

pre-patch:
	@${PERL} -pi -e 's,<malloc.h>,<stdlib.h>,' ${WRKSRC}/image2/picinfo.h

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/Docs/* ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
