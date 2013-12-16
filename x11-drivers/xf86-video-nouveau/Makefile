# Created by: Anonymous <swell.k@gmail.com>
# $FreeBSD$

PORTNAME=	xf86-video-nouveau
PORTVERSION=	0.0.10.${SNAPDATE}
DISTVERSIONSUFFIX=.${SNAPREV}
PORTREVISION=	4
CATEGORIES=	x11-drivers
MASTER_SITES=	ftp://ftp.lissyara.su/users/Guest/distfiles/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Free nouveau display driver for nvidia-based cards

XORG_CAT=	driver
USE_XORG=	xf86driproto glproto

# also doesn't work with mesa (libGL) version higher than 7.4.x
BROKEN=		Does not build
DEPRECATED=	Not supported, missing kernel support. use the nvidia driver.
EXPIRATION_DATE=2014-01-31

post-configure:
	${REINPLACE_CMD} '/NV_DRIVER_DATE/s/".*"/"${SNAPDATE}.${SNAPREV}"/' ${WRKSRC}/config.h

post-install:	.SILENT
	${ECHO_MSG}
	${CAT} ${PKGMESSAGE}
	${ECHO_MSG}

GIT_WORK=	${WRKDIR}/${PORTNAME}.git-clone
GIT_DATE=	$$(date -ur$$(git log --pretty=format:%ct -1 ) +%Y%m%d)
GIT_REV=	$$(git log --pretty=format:%h -1)
NEWDISTNAME=	${DISTNAME:S/${SNAPDATE}.${SNAPREV}$$//}${GIT_DATE}.${GIT_REV}

maint-gen-distfile:
	git clone git://anongit.freedesktop.org/nouveau/xf86-video-nouveau \
		${GIT_WORK}

	( cd ${GIT_WORK}; \
	  git log --stat >ChangeLog; \
	  autoreconf -if; \
	  ${TAR} cjf ${DISTDIR}/${DIST_SUBDIR}/${NEWDISTNAME}${EXTRACT_SUFX} \
	  	--exclude '.git*' --exclude autogen.sh \
		--exclude autom4te.cache \
	  	-s "|${GIT_WORK}|${NEWDISTNAME}|" \
	  	${GIT_WORK}; \
	  ${ECHO_CMD} "SNAPDATE=	${GIT_DATE}" \
		>${MASTERDIR}/Makefile.rev; \
	  ${ECHO_CMD} "SNAPREV=	${GIT_REV}" \
		>>${MASTERDIR}/Makefile.rev )

	${RM} -rf ${GIT_WORK}

.include "Makefile.rev"
.include <bsd.port.mk>
