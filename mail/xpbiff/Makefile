# Created by: Yoshiro MIHIRA <sanpei@yy.cs.keio.ac.jp>
# $FreeBSD$

PORTNAME?=	xpbiff
PORTVERSION?=	1.27
PORTREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=     sanpei

DISTNAME=	xpbiff
DISTFILES=	xpbiff-1.27-with-YOUBIN.tar.gz.uu

MAINTAINER?=	sanpei@FreeBSD.org
COMMENT?=	Replacement for xbiff that handles popup window with mail header

USES=		imake
USE_GCC=	any
USE_XORG=	xpm xaw xmu
NO_INSTALL_MANPAGES=	yes
PLIST_FILES=	bin/xpbiff
WRKSRC=		${WRKDIR}/xpbiff

.if defined(PREFIX) && ${PREFIX} != ${LOCALBASE}
YOUBINBINDIR=	${PREFIX}
.else
YOUBINBINDIR=	${LOCALBASE}
.endif

.include <bsd.port.pre.mk>

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@(cd ${WRKDIR}; \
	  if [ ! -f ${DISTDIR}/${DISTNAME}.tar.gz ]; then \
	    uudecode -p ${DISTDIR}/${DISTFILES} | ${TAR} xzf -; \
	  else \
	    ${TAR} xzf ${DISTDIR}/${DISTNAME}.tar.gz; \
	  fi)

pre-patch:
	@(${RM} -rf ${WRKSRC}/LocPixmap.c; \
	  ${CP} ${FILESDIR}/LocPixmap.c ${WRKSRC} );

post-patch:
.if defined(YOUBIN)
	@(cd ${WRKSRC}; ${PATCH} -s < ${FILESDIR}/xpbiff.youbin.diff );
.endif
	@${MV} ${WRKSRC}/config.h ${WRKSRC}/config.h.org
	@${SED} "s=%YOUBINBINDIR%=${YOUBINBINDIR}/bin=" < ${WRKSRC}/config.h.org > ${WRKSRC}/config.h

.include <bsd.port.post.mk>
