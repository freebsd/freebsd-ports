# Ports collection makefile for: webcamd
# Date created: 13 January 2010
# Whom:         Andrew Thompson <thompsa@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	webcamd
PORTVERSION=	0.1.10
CATEGORIES=	multimedia
MASTER_SITES=	http://www.selasky.org/hans_petter/video4bsd/releases/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	A port of Linux USB webcam and DVB drivers into userspace

BUILD_DEPENDS=	v4l_compat>=1.0.20100321:${PORTSDIR}/multimedia/v4l_compat \
		cuse4bsd-kmod>=0.1.8:${PORTSDIR}/multimedia/cuse4bsd-kmod

LIB_DEPENDS=	v4l1.0:${PORTSDIR}/multimedia/libv4l

USE_RC_SUBR=	webcamd
USE_BZIP2=	yes
USE_LDCONFIG=	yes

LIBDIR=		${PREFIX}/lib

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
IGNORE=		requires FreeBSD 8.0-RELEASE or later
.endif

post-patch:
	@cd ${WRKSRC}/patches; ${SH} ./do_patch.sh
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${PREFIX}/etc/devd
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|g" \
		< ${FILESDIR}/webcamd.conf.in > ${WRKDIR}/webcamd.conf
	${INSTALL_DATA} "${WRKDIR}/webcamd.conf" ${PREFIX}/etc/devd
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
