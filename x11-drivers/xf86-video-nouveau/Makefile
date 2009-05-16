# New ports collection makefile for:	xf86-video-nouveau
# Date Created:				29 Jan 2009
# Whom:					Anonymous <swell.k@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	xf86-video-nouveau
PORTVERSION=	0.0.10.${SNAPDATE}
DISTVERSIONSUFFIX=.${SNAPREV}
CATEGORIES=	x11-drivers
MASTER_SITES=	ftp://ftp.lissyara.su/users/Guest/distfiles/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Free nouveau display driver for nvidia-based cards

XORG_CAT=	driver
USE_XORG=	videoproto xextproto xf86driproto glproto
MAN4=		nouveau.4x

MAKE_JOBS_SAFE=	yes

SNAPDATE=	20090514
SNAPREV=	9656762

post-configure:
	${REINPLACE_CMD} '/NV_DRIVER_DATE/s/".*"/"${SNAPDATE}.${SNAPREV}"/' ${WRKSRC}/config.h

GIT_WORK=	${WRKDIR}/${PORTNAME}.git-clone
GIT_REV=	$$(date -ur$$(git log --pretty=format:%ct -1 \
			) +%Y%m%d).$$(git log --pretty=format:%h -1)

maint-gen-distfile:
	git clone git://anongit.freedesktop.org/nouveau/xf86-video-nouveau \
		${GIT_WORK}

	( cd ${GIT_WORK}; \
	  git log --stat >ChangeLog; \
	  autoreconf -if; \
	  ${TAR} cjf ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME:S/${SNAPDATE}.${SNAPREV}$$//}${GIT_REV}.tar.bz2 \
	  	--exclude '.git*' --exclude autogen.sh --exclude autom4te.cache \
	  	-s "|${GIT_WORK}|${DISTNAME:S/${SNAPDATE}.${SNAPREV}$$//}${GIT_REV}|" \
	  	${GIT_WORK} )

	${RM} -rf ${GIT_WORK}

.include <bsd.port.mk>
