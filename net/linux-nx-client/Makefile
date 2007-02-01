# New ports collection makefile for:	linux-nx-client
# Date created:			01 Sep 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		linux-nx-client
PORTVERSION=		2.1.0
PORTREVISON=		1
CATEGORIES=		net
MASTER_SITES=		http://web04.nomachine.com/download/${PORTVERSION}/Linux/
DISTNAME=		nxclient-${PORTVERSION}-11.i386

MAINTAINER=		ports@FreeBSD.org
COMMENT=		The NoMachine NX client

RUN_DEPENDS=		${LINUXBASE}/usr/lib/libaudiofile.so.0:${PORTSDIR}/audio/linux-libaudiofile \
			${LINUXBASE}/usr/lib/libjpeg.so.62:${PORTSDIR}/graphics/linux-jpeg \
			${LINUXBASE}/usr/lib/libpng12.so.0:${PORTSDIR}/graphics/linux-png

NO_WRKSUBDIR=		yes
ONLY_FOR_ARCHS=		i386 amd64
USE_LINUX=		yes
NO_BUILD=		yes
INSTALL_ICONS=		yes

NXSRC=			${WRKSRC}/NX
NXDST=			${PREFIX}/lib/linux-nx-client

PLIST_SUB+=		PORTVERSION=${PORTVERSION}

do-install:
	${MKDIR} ${NXDST}/bin
	${INSTALL_PROGRAM} ${NXSRC}/bin/* ${NXDST}/bin
	${MKDIR} ${NXDST}/lib
.for f in libXcomp libXcompsh
	${INSTALL_DATA} ${NXSRC}/lib/${f}.so.${PORTVERSION} ${NXDST}/lib
	${LN} -sf ${f}.so.${PORTVERSION} ${NXDST}/lib/${f}.so
	${LN} -sf ${f}.so.${PORTVERSION} ${NXDST}/lib/${f}.so.2
.endfor
	${INSTALL_DATA} ${NXSRC}/lib/libcrypto.so.0.9.8 ${NXDST}/lib
	${LN} -sf libcrypto.so.0.9.8 ${NXDST}/lib/libcrypto.so
	${MKDIR} ${NXDST}/share
	${INSTALL_DATA} ${NXSRC}/share/keyboards ${NXDST}/share
	${MKDIR} ${NXDST}/share/keys
	${INSTALL_DATA} ${NXSRC}/share/keys/* ${NXDST}/share/keys
	${MKDIR} ${NXDST}/share/images
	${INSTALL_DATA} ${NXSRC}/share/images/* ${NXDST}/share/images

	${MKDIR} ${LOCALBASE}/share/gnome/pixmaps
	${INSTALL_DATA} ${NXSRC}/share/icons/*.png ${LOCALBASE}/share/gnome/pixmaps
	${MKDIR} ${LOCALBASE}/share/icons/crystalsvg/48x48 \
		${LOCALBASE}/share/icons/crystalsvg/32x32
	${INSTALL_DATA} ${NXSRC}/share/icons/nx-desktop.png \
		${LOCALBASE}/share/icons/crystalsvg/48x48
.for f in nx.png nxclient-admin.png nxclient-wizard.png
	${INSTALL_DATA} ${NXSRC}/share/icons/${f} \
		${LOCALBASE}/share/icons/crystalsvg/32x32
.endfor

.for f in nxclient nxesd nxkill nxservice nxssh
	${ECHO_CMD} "#!/bin/sh" > ${WRKSRC}/${f}
	${ECHO_CMD} "export NXDIR=${NXDST}" >> ${WRKSRC}/${f}
	${ECHO_CMD} "exec \$$NXDIR/bin/${f} \"\$$@\"" >> ${WRKSRC}/${f}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/bin
	${BRANDELF} -t Linux ${NXDST}/bin/${f}
.endfor

.include <bsd.port.mk>
