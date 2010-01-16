# Ports collection makefile for: webcamd
# Date created: 13 January 2010
# Whom:         Andrew Thompson <thompsa@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	webcamd
PORTVERSION=	0.1.0
CATEGORIES=	multimedia
MASTER_SITES=	http://www.selasky.org/hans_petter/video4bsd/releases/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	A port of Video4Linux USB webcam drivers into userspace

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat \
		${LOCALBASE}/include/video4bsd.h:${PORTSDIR}/multimedia/video4bsd-kmod
LIB_DEPENDS=	v4l1.0:${PORTSDIR}/multimedia/libv4l

USE_RC_SUBR=	webcamd
CFLAGS+=	-I${LOCALBASE}/include
USE_BZIP2=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
IGNORE=		requires FreeBSD 8.0-RELEASE or later
.endif

post-patch:
	cd ${WRKSRC}/patches; ${SH} ./do_patch.sh
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${PREFIX}/etc/devd
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|g" \
		< ${FILESDIR}/webcamd.conf.in > ${WRKDIR}/webcamd.conf
	${INSTALL_DATA} "${WRKDIR}/webcamd.conf" ${PREFIX}/etc/devd
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
