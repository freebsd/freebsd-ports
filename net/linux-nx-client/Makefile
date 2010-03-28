# New ports collection makefile for:	linux-nx-client
# Date created:			01 Sep 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		linux-nx-client
PORTVERSION=		3.4.0
PORTREVISION=	1
CATEGORIES=		net
MASTER_SITES=		http://web04.nomachine.com/download/${PORTVERSION}/Linux/
DISTNAME=		nxclient-${PORTVERSION}-5.i386

MAINTAINER=		ports@FreeBSD.org
COMMENT=		The NoMachine NX client

NO_WRKSUBDIR=		yes
ONLY_FOR_ARCHS=		i386 amd64
USE_LINUX=		yes
USE_LINUX_APPS=		libaudiofile jpeg png
INSTALLS_ICONS=		yes
USE_LDCONFIG=		yes

NXSRC=			${WRKSRC}/NX
NXDST=			${PREFIX}/lib/linux-nx-client

PLIST_SUB+=		PORTVERSION=${PORTVERSION}

# Patch binary to expect EINVAL (FreeBSD) instead of EOPNOTSUPP (Linux) when
# trying to set TCP_NODELAY on the X11 unix domain socket.
do-build:
	${REINPLACE_CMD} -e 's/\x83\xf8\x5f\x0f\x84/\x83\xf8\x16\x0f\x84/' \
		${NXSRC}/lib/libXcomp.so.${PORTVERSION}

do-install:
	${MKDIR} ${NXDST}/bin
	${INSTALL_PROGRAM} ${NXSRC}/bin/* ${NXDST}/bin
	${MKDIR} ${NXDST}/lib
.for f in libXcomp libXcompsh
	${INSTALL_DATA} ${NXSRC}/lib/${f}.so.${PORTVERSION} ${NXDST}/lib
	${LN} -sf ${f}.so.${PORTVERSION} ${NXDST}/lib/${f}.so
	${LN} -sf ${f}.so.${PORTVERSION} ${NXDST}/lib/${f}.so.3
.endfor
	${INSTALL_DATA} ${NXSRC}/lib/libcrypto.so.0.9.8 ${NXDST}/lib
	${LN} -sf libcrypto.so.0.9.8 ${NXDST}/lib/libcrypto.so
	${MKDIR} ${NXDST}/share
	${INSTALL_DATA} ${NXSRC}/share/keyboards ${NXDST}/share
	${MKDIR} ${NXDST}/share/keys
	${INSTALL_DATA} ${NXSRC}/share/keys/* ${NXDST}/share/keys
	${MKDIR} ${NXDST}/share/images
	${INSTALL_DATA} ${NXSRC}/share/images/* ${NXDST}/share/images

	${MKDIR} ${LOCALBASE}/share/pixmaps
	${INSTALL_DATA} ${NXSRC}/share/icons/48x48/*.png ${LOCALBASE}/share/pixmaps
	${MKDIR} ${LOCALBASE}/share/icons/crystalsvg/48x48 \
		${LOCALBASE}/share/icons/crystalsvg/32x32 \
		${LOCALBASE}/share/icons/crystalsvg/22x22 \
		${LOCALBASE}/share/icons/crystalsvg/16x16
.for x in 16x16 22x22 32x32 48x48
	${MKDIR} ${LOCALBASE}/share/icons/crystalsvg/${x}
	${INSTALL_DATA} ${NXSRC}/share/icons/${x}/* \
		${LOCALBASE}/share/icons/crystalsvg/${x}
.endfor

.for f in nxclient nxesd nxkill nxservice nxssh
	${ECHO_CMD} "#!/bin/sh" > ${WRKSRC}/${f}
	${ECHO_CMD} "export NXDIR=${NXDST}" >> ${WRKSRC}/${f}
	${ECHO_CMD} "exec \$$NXDIR/bin/${f} \"\$$@\"" >> ${WRKSRC}/${f}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/bin
	${BRANDELF} -t Linux ${NXDST}/bin/${f}
.endfor

.include <bsd.port.mk>
