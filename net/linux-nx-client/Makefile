# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=		linux-nx-client
PORTVERSION=		3.4.0
PORTREVISION=		2
CATEGORIES=		net
MASTER_SITES=		http://web04.nomachine.com/download/${PORTVERSION}/Linux/
DISTNAME=		nxclient-${PORTVERSION}-5.i386

MAINTAINER=		ports@FreeBSD.org
COMMENT=		The NoMachine NX client

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2014-03-10

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
	${MKDIR} ${STAGEDIR}${NXDST}/bin
	${INSTALL_PROGRAM} ${NXSRC}/bin/* ${STAGEDIR}${NXDST}/bin
	${MKDIR} ${STAGEDIR}${NXDST}/lib
.for f in libXcomp libXcompsh
	${INSTALL_DATA} ${NXSRC}/lib/${f}.so.${PORTVERSION} ${STAGEDIR}${NXDST}/lib
	${LN} -sf ${f}.so.${PORTVERSION} ${STAGEDIR}${NXDST}/lib/${f}.so
	${LN} -sf ${f}.so.${PORTVERSION} ${STAGEDIR}${NXDST}/lib/${f}.so.3
.endfor
	${INSTALL_DATA} ${NXSRC}/lib/libcrypto.so.0.9.8 ${STAGEDIR}${NXDST}/lib
	${LN} -sf libcrypto.so.0.9.8 ${STAGEDIR}${NXDST}/lib/libcrypto.so
	${MKDIR} ${STAGEDIR}${NXDST}/share
	${INSTALL_DATA} ${NXSRC}/share/keyboards ${STAGEDIR}${NXDST}/share
	${MKDIR} ${STAGEDIR}${NXDST}/share/keys
	${INSTALL_DATA} ${NXSRC}/share/keys/* ${STAGEDIR}${NXDST}/share/keys
	${MKDIR} ${STAGEDIR}${NXDST}/share/images
	${INSTALL_DATA} ${NXSRC}/share/images/* ${STAGEDIR}${NXDST}/share/images

	${MKDIR} ${STAGEDIR}${LOCALBASE}/share/pixmaps
	${INSTALL_DATA} ${NXSRC}/share/icons/48x48/*.png ${STAGEDIR}${LOCALBASE}/share/pixmaps
	${MKDIR} ${STAGEDIR}${LOCALBASE}/share/icons/crystalsvg/48x48 \
		${STAGEDIR}${LOCALBASE}/share/icons/crystalsvg/32x32 \
		${STAGEDIR}${LOCALBASE}/share/icons/crystalsvg/22x22 \
		${STAGEDIR}${LOCALBASE}/share/icons/crystalsvg/16x16
.for x in 16x16 22x22 32x32 48x48
	${MKDIR} ${STAGEDIR}${LOCALBASE}/share/icons/crystalsvg/${x}
	${INSTALL_DATA} ${NXSRC}/share/icons/${x}/* \
		${STAGEDIR}${LOCALBASE}/share/icons/crystalsvg/${x}
.endfor

.for f in nxclient nxesd nxkill nxservice nxssh
	${BRANDELF} -t Linux ${NXSRC}/bin/${f}
	${ECHO_CMD} "#!/bin/sh" > ${WRKSRC}/${f}
	${ECHO_CMD} "export NXDIR=${NXDST}" >> ${WRKSRC}/${f}
	${ECHO_CMD} "exec \$$NXDIR/bin/${f} \"\$$@\"" >> ${WRKSRC}/${f}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
