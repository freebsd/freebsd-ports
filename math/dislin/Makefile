# New ports collection makefile for:	linux-dislin
# Date created:				2003-12-14
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	dislin
PORTVERSION=	8.2
PORTREVISION=	1
CATEGORIES=	math linux
MASTER_SITES=	ftp://ftp.gwdg.de/pub/grafik/dislin/linux/${MACHINE_ARCH}/
PKGNAMEPREFIX=	linux-
EXTRACT_SUFX=	.linux.tar.gz
DIST_SUBDIR=	${MACHINE_ARCH}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A scientific data plotting package

RUN_DEPENDS=	${LINUXBASE}/usr/X11R6/lib/libXrender.so.1:${PORTSDIR}/x11/linux-XFree86-libs

BROKEN=		Unfetchable

ONLY_FOR_ARCHS=	i386 alpha
NO_BUILD=	yes
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	${DISLIN_DIR}/lib

MD5_FILE=	${MASTERDIR}/distinfo.${MACHINE_ARCH}
PLIST=		${PKGDIR}/pkg-plist.${MACHINE_ARCH}
PKGMESSAGE=	${WRKDIR}/pkg-message
DISLIN_DIR=	${PREFIX}/dislin
PROGRAMS=	clink disaps disdrv disdrv_nw disdrv_w disgif dishlp dishpj \
		disimg disman dismov disprv distif dlink f2clink g77link

do-configure:
	${SED} -e 's,%%DISLIN_DIR%%,${DISLIN_DIR},' \
	    <${FILESDIR}/dislin-wrapper.sh >${WRKDIR}/dislin.sh
	${SED} -e 's,%%DISLIN_DIR%%,${DISLIN_DIR},' \
	    <${FILESDIR}/pkg-message >${WRKDIR}/pkg-message

do-install:
	(cd ${WRKSRC} && ${ENV} DISLIN=${DISLIN_DIR} ${SH} INSTALL)
	${INSTALL_SCRIPT} ${WRKDIR}/dislin.sh ${DISLIN_DIR}/bin
.for _program in ${PROGRAMS}
	${LN} -s ${DISLIN_DIR}/bin/dislin.sh ${PREFIX}/bin/${_program}
.endfor

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
