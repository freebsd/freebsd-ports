# New ports collection makefile for:    xpbiff
# Version required:     1.27
# Date created:         2 April 1997
# Whom:                 Yoshiro MIHIRA <sanpei@yy.cs.keio.ac.jp>
#
# $Id: Makefile,v 1.4 1998/09/15 11:13:29 asami Exp $

DISTNAME=	xpbiff
PKGNAME?=	xpbiff-1.27
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.ics.es.osaka-u.ac.jp/pub/xpbiff/
DISTFILES=	xpbiff-1.27-with-YOUBIN.tar.gz.uu

MAINTAINER=	sanpei@yy.cs.keio.ac.jp

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes
WRKSRC=		${WRKDIR}/xpbiff

.if defined(PREFIX) && ${PREFIX} != ${LOCALBASE}
YOUBINBINDIR= ${PREFIX}
.else
YOUBINBINDIR= ${LOCALBASE}
.endif

do-extract:
	@(cd ${DISTDIR}; \
	  if [ ! -f ${DISTNAME}.tar.gz ]; then \
	    uudecode ${DISTFILES} ; \
	  fi)
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@(cd ${WRKDIR}; tar -xzf \
		${DISTDIR}/${DISTNAME}.tar.gz)

pre-patch:
	@(${RM} -rf ${WRKSRC}/LocPixmap.c; \
	  ${CP} ${FILESDIR}/LocPixmap.c ${WRKSRC} );

post-patch:
	@(for libfile in /usr/lib/libxpg4*; do \
		if [ ! "$$libfile" = "" ]; then \
			${ECHO_MSG} "===>  Finding the xpg4 library in /usr/lib"; \
			(cd ${WRKSRC}; ${PATCH} -s < ${FILESDIR}/Imakefile.xpg4.diff );\
			break 1; \
		fi; \
	  done)
.if defined(YOUBIN)
	@(cd ${WRKSRC}; ${PATCH} -s < ${FILESDIR}/xpbiff.youbin.diff );
.endif
	@${MV} ${WRKSRC}/config.h ${WRKSRC}/config.h.org
	@${SED} "s=%YOUBINBINDIR%=${YOUBINBINDIR}/bin=" < ${WRKSRC}/config.h.org > ${WRKSRC}/config.h

.include <bsd.port.mk>
