# New ports collection makefile for: nspluginwrapper
# Date created:         30 March 2007
# Whom:                 Dave Grochowski
#
# $FreeBSD$
#

PORTNAME=	nspluginwrapper
PORTVERSION=	1.3.0
PORTREVISION=	7
CATEGORIES=	www linux emulators
MASTER_SITES=	LOCAL/jkim
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${BINFILE}${EXTRACT_SUFX}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	A compatibility plugin for Mozilla NPAPI (development version)

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl

LATEST_LINK=	${PORTNAME}-devel

CONFLICTS=	nspluginwrapper-1.2.*

BINFILE=	${PORTNAME}-i386-${PORTVERSION}-4

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

CONFIGURE_ARGS=	--enable-generic --enable-strip --prefix=${PREFIX} \
		--target-os=linux --target-cpu=i386 \
		--with-cc=${CC} --with-cxx=${CXX} \
		--with-x11-prefix=${LOCALBASE}

LIBDIR=		${PREFIX}/lib/${PORTNAME}

PLIST_SUB=	LIBDIR="${LIBDIR:C/^${PREFIX}\///}" HOST_ARCH="${HOST_ARCH}"

SUB_FILES=	npviewer
SUB_LIST+=	NSPLUGINWRAPPER="${LIBDIR}"

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
HOST_ARCH=	x86_64
.else
HOST_ARCH=	${ARCH}
.endif

post-patch:
	${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},g' \
	    ${WRKSRC}/src/npw-config.c

post-install:
	${MKDIR} ${LIBDIR}/i386/linux
	${INSTALL_PROGRAM} ${WRKDIR}/usr/lib/nspluginwrapper/i386/linux/*.bin \
	    ${WRKDIR}/usr/lib/nspluginwrapper/i386/linux/*.so \
	    ${LIBDIR}/i386/linux/
	${INSTALL_SCRIPT} ${WRKDIR}/npviewer ${LIBDIR}/i386/linux/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
