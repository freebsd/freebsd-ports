# New ports collection makefile for:	xnc
# Date created:		5 February 1999
# Whom:			Dima Sivachenko	<dima@chg.ru>
#
# $FreeBSD$
#

PORTNAME=	xnc
PORTVERSION= 	4.2.1
CATEGORIES=	x11-fm
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://www.xnc.dubna.su/src/
MASTER_SITE_SUBDIR=	X11/desktop
DISTNAME=	${PKGNAME}.src

MAINTAINER=	dima@Chg.RU

# xnc will use the following programs if you have them installed.
#RUN_DEPENDS=	zip:${PORTSDIR}/archivers/zip		\
#		unzip:${PORTSDIR}/archivers/unzip	\
#		rpm:${PORTSDIR}/misc/rpm		\
#		rar:${PORTSDIR}/archivers/rar		\
#		unarj:${PORTSDIR}/archivers/unarj	\
#		lha:${PORTSDIR}/archivers/lha		\
#		bzip2:${PORTSDIR}/archivers/bzip2
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.3:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/${PKGNAME}
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		es.1 ives.1 vs.1 xjpegroot.1 xnc.1 xnlaunch.1

post-install:
.if !defined(NOPORTDOCS)
		${MKDIR} ${PREFIX}/share/doc/xnc
		${INSTALL_DATA} ${WRKSRC}/Docs/* ${PREFIX}/share/doc/xnc
.endif
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
