# New ports collection makefile for: nspluginwrapper
# Date created:         30 March 2007
# Whom:                 Dave Grochowski
#
# $FreeBSD$
#

PORTNAME=	nspluginwrapper
PORTVERSION=	1.2.2
PORTREVISION=	4
CATEGORIES=	www linux emulators
MASTER_SITES=	http://gwenole.beauchesne.info/projects/nspluginwrapper/files/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${RPMFILE}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	malus.x@gmail.com
COMMENT=	A compatibility plugin for Netscape 4 (NPAPI) plugins

EXTRACT_DEPENDS=	rpm2cpio:${PORTSDIR}/archivers/rpm
LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl

RPMFILE=	${PORTNAME}-i386-${PORTVERSION}-1.x86_64.rpm

ONLY_FOR_ARCHS=	i386 amd64

USE_BZIP2=	yes
USE_LINUX=	yes
USE_LINUX_APPS=	gtk2
USE_XORG=	x11 xext xt
USE_GNOME=	glib20 gtk20 pkgconfig

CFLAGS+=	-std=c99

USE_LDCONFIG=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--enable-generic --prefix=${PREFIX} --target-os=linux \
		--target-cpu=i386 --with-x11-prefix=${LOCALBASE} \
		--with-cc=${CC} --with-cxx=${CXX}

LIBDIR=		${PREFIX}/lib/${PORTNAME}

PLIST_SUB=	LIBDIR="${LIBDIR:C/^${PREFIX}\///}" ARCH="${ARCH}"

# We must manually extract, modify, and install the Linux version of npviewer.
post-extract:
	cd ${WRKSRC} &&	rpm2cpio ${DISTDIR}/${RPMFILE} | ${CPIO} -id
	${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' \
		${WRKSRC}/usr/lib/nspluginwrapper/i386/linux/npviewer
	${RM} ${WRKSRC}/usr/lib/nspluginwrapper/i386/linux/npviewer.bak

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},g' \
		${WRKSRC}/src/npw-config.c
	${RM} ${WRKSRC}/usr/lib/nspluginwrapper/i386/linux/npviewer.orig

post-install:
	${MKDIR} ${LIBDIR}/i386/linux
	${INSTALL_SCRIPT} ${WRKSRC}/usr/lib/nspluginwrapper/i386/linux/* \
	     ${LIBDIR}/i386/linux/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
