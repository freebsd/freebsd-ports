# New ports collection makefile for:	xnc
# Version required:	4.2.1
# Date created:		5 February 1999
# Whom:			Dima Sivachenko	<dima@chg.ru>
#
# $FreeBSD$
#

DISTNAME=	xnc-4.2.1.src
PKGNAME=	xnc-4.2.1
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.xnc.dubna.su/src/ \
		ftp://ftp.chg.ru/pub/Linux/sunsite/X11/desktop/	\
		ftp://sunsite.unx.edu/pub/Linux/X11/desktop/

MAINTAINER=	dima@Chg.RU

# xnc will use the following programs if you have them installed.
#RUN_DEPENDS=	zip:${PORTSDIR}/archivers/zip		\
#		unzip:${PORTSDIR}/archivers/unzip	\
#		rpm:${PORTSDIR}/misc/rpm		\
#		rar:${PORTSDIR}/archivers/rar		\
#		unarj:${PORTSDIR}/archivers/unarj	\
#		lha:${PORTSDIR}/archivers/lha		\
#		bzip2:${PORTSDIR}/archivers/bzip2

USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/${PKGNAME}
GNU_CONFIGURE=	yes

MAN1=		es.1 ives.1 vs.1 xjpegroot.1 xnc.1 xnlaunch.1

post-install:
.if !defined(NOPORTDOCS)
		${MKDIR} ${PREFIX}/share/doc/xnc
		${INSTALL_DATA} ${WRKSRC}/Docs/* ${PREFIX}/share/doc/xnc
.endif
		@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
