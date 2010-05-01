# New ports collection makefile for:	xf86-video-nouveau
# Date Created:				29 Jan 2009
# Whom:					Anonymous <swell.k@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	xf86-video-nouveau
PORTVERSION=	0.0.10.${SNAPDATE}
DISTVERSIONSUFFIX=.${SNAPREV}
PORTREVISION=	2
CATEGORIES=	x11-drivers
MASTER_SITES=	ftp://ftp.lissyara.su/users/Guest/distfiles/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Free nouveau display driver for nvidia-based cards

XORG_CAT=	driver
USE_XORG=	videoproto xextproto xf86driproto glproto
MAN4=		nouveau.4x

MAKE_JOBS_SAFE=	yes

.if defined(WITHOUT_NOUVEAU)
BROKEN=		Please disable WITHOUT_NOUVEAU global macro.
.endif

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
