# New ports collection makefile for:   linux-realplayer
# Date created:        31 January 1999
# Whom:                Kris Kennaway <kkennawa@physics.adelaide.edu.au>
#
# $FreeBSD$
#

PORTNAME=	linux-realplayer
PORTVERSION=	8.cs2
PORTREVISION=	5
CATEGORIES=	multimedia audio linux
MASTER_SITES=	http://docs.real.com/docs/playerpatch/unix/:update
DISTFILES=	${MAINDIST} ${UPDATEDIST:S/$/:update/}
EXTRACT_ONLY=	${UPDATEDIST}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Linux RealPlayer 8.0 from RealNetworks

EXTRACT_DEPENDS=	rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio
RUN_DEPENDS=	${LINUXBASE}/lib/libc.so.6:${PORTSDIR}/emulators/linux_base \
		${LINUXBASE}/usr/lib/libesd.so.0:${PORTSDIR}/audio/linux-esound

MAINDIST=	rp${PORTVERSION:R}_linux20_libc6_i386_${PORTVERSION:E}_rpm
UPDATEDIST=	rv9_libc6_i386_cs2.tgz

RADIR=		${PREFIX}/lib/RealPlayer${PORTVERSION:R}
WRKSRC=		${WRKDIR}/usr/lib/RealPlayer${PORTVERSION:R}
PLUGINSDIR=	${PREFIX}/lib/netscape-linux/plugins
RABINDIR=	${PREFIX}/bin

# Linux binary should not be stripped by INSTALL_PROGRAM
# because as a side effect it brands the binary as FreeBSD.
STRIP=

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${MAINDIST})
IGNORE=		may not be automatically fetched due to licensing\
		restrictions.  You MUST manually fetch the Linux RPM version after\
		reading and agreeing to the license at:\
		http://forms.real.com/real/player/unix/unix.html \
		- once ${DISTFILES} has been downloaded, move it to\
		${DISTDIR} and then restart this build.
.endif

USE_REINPLACE=	yes
ONLY_FOR_ARCHS=	i386
NO_CDROM=	"Redistribution not allowed"
NO_BUILD=	yes

post-extract:
	cd ${WRKDIR}; rpm2cpio.pl ${DISTDIR}/${MAINDIST} | ${CPIO} -id --quiet

post-patch:
	${REINPLACE_CMD} -e \
		"s@/usr/lib@${PREFIX}/lib@" ${WRKSRC}/postinstall.sh

do-install:
	${MKDIR} ${RADIR}
.for f in mimeinstall.sh pluginstall.sh postinstall.sh
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${RADIR}
.endfor
.for f in realplay rpnp.so
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${RADIR}
.endfor
.for f in LICENSE Mailcap Mime.types README app.kdelnk audiosig.rm \
	firstrun.rm mime.kdelnk raclass.zip \
	realplay.desktop rp7.xpm rp7doc.png rp7doc.xpm rp7mini.xpm
	${INSTALL_DATA} ${WRKSRC}/${f} ${RADIR}
.endfor
.for d in Codecs Common Plugins
	${MKDIR} ${RADIR}/${d}
	${INSTALL_PROGRAM} ${WRKSRC}/${d}/*.so* ${RADIR}/${d}
.endfor
	${MKDIR} ${RADIR}/Plugins/ExtResources
	${INSTALL_PROGRAM} ${WRKSRC}/Plugins/ExtResources/* ${RADIR}/Plugins/ExtResources/
	${INSTALL_PROGRAM} ${WRKDIR}/rv9/codecs/drv4.so.6.0 ${RADIR}/Codecs/
	${INSTALL_PROGRAM} ${WRKDIR}/rv9/codecs/rv40.so.6.0 ${RADIR}/Codecs/

	${LN} -sf ${RADIR}/realplay ${RABINDIR}

.if exists(${PLUGINSDIR})
	${LN} -sf ${RADIR}/raclass.zip ${PLUGINSDIR}
	${LN} -sf ${RADIR}/rpnp.so ${PLUGINSDIR}
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/RealPlayer8
	${INSTALL_DATA} ${WRKSRC}/Help/readme ${PREFIX}/share/doc/RealPlayer8
	${INSTALL_DATA} ${WRKSRC}/Help/realplay.htm ${PREFIX}/share/doc/RealPlayer8
	${MKDIR} ${PREFIX}/share/doc/RealPlayer8/realplay
	${INSTALL_DATA} ${WRKSRC}/Help/realplay/*.htm ${PREFIX}/share/doc/RealPlayer8/realplay
	${MKDIR} ${PREFIX}/share/doc/RealPlayer8/realplay/pics
	${INSTALL_DATA} ${WRKSRC}/Help/realplay/pics/* ${PREFIX}/share/doc/RealPlayer8/realplay/pics
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
