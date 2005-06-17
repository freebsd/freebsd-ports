# New ports collection makefile for:	linux-nx-client
# Date created:			01 Sep 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		linux-nx-client
PORTVERSION=		1.4.0
PORTREVISION=		2
CATEGORIES=		net
MASTER_SITES=		http://www.nomachine.com/download/nxclient/${PORTVERSION}/Linux-Static-Tar/
DISTNAME=		nxclient-${PORTVERSION}-91.i386

MAINTAINER=		jylefort@FreeBSD.org
COMMENT=		The NoMachine NX client

RUN_DEPENDS=		${LINUXBASE}/usr/lib/libjpeg.so.62:${PORTSDIR}/graphics/linux-jpeg

NO_WRKSUBDIR=		yes
ONLY_FOR_ARCHS=		i386
USE_LINUX=		yes
USE_X_PREFIX=		yes
NO_BUILD=		yes

NXSRC=			${WRKSRC}/NX
NXDST=			${PREFIX}/lib/linux-nx-client

PLIST_SUB+=		PORTVERSION=${PORTVERSION}

post-extract:
	@${CP} ${NXSRC}/share/applnk/NX\ Client\ for\ Linux/* ${WRKSRC}

do-install:
	${MKDIR} ${NXDST}/bin
	${INSTALL_PROGRAM} ${NXSRC}/bin/* ${NXDST}/bin
	${MKDIR} ${NXDST}/lib
	${INSTALL_DATA} ${NXSRC}/lib/libXcomp.so.${PORTVERSION} ${NXDST}/lib
	${LN} -sf libXcomp.so.${PORTVERSION} ${NXDST}/lib/libXcomp.so
	${LN} -sf libXcomp.so.${PORTVERSION} ${NXDST}/lib/libXcomp.so.1
	${MKDIR} ${NXDST}/share
	${INSTALL_DATA} ${NXSRC}/share/client.id_dsa.key ${NXDST}/share
	${MKDIR} ${NXDST}/share/images
	${INSTALL_DATA} ${NXSRC}/share/images/* ${NXDST}/share/images

	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/*.desktop ${PREFIX}/share/applications
	${MKDIR} ${PREFIX}/share/gnome/pixmaps
	${INSTALL_DATA} ${NXSRC}/share/icons/* ${PREFIX}/share/gnome/pixmaps
	${MKDIR} ${LOCALBASE}/share/icons/crystalsvg/48x48 \
		${LOCALBASE}/share/icons/crystalsvg/32x32
	${INSTALL_DATA} ${NXSRC}/share/icons/nx-desktop.png \
		${LOCALBASE}/share/icons/crystalsvg/48x48
.for f in nx.png nxclient-admin.png nxclient-wizard.png
	${INSTALL_DATA} ${NXSRC}/share/icons/${f} \
		${LOCALBASE}/share/icons/crystalsvg/32x32
.endfor

.for f in nxclient nxprint nxproxy nxssh
	${ECHO_CMD} "#!/bin/sh" > ${WRKSRC}/${f}
	${ECHO_CMD} "export NXDIR=${NXDST}" >> ${WRKSRC}/${f}
	${ECHO_CMD} "exec \$$NXDIR/bin/${f} \"\$$@\"" >> ${WRKSRC}/${f}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/bin
	${BRANDELF} -t Linux ${NXDST}/bin/${f}
.endfor

.include <bsd.port.mk>
