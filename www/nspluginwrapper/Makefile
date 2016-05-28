# Created by: Dave Grochowski
# $FreeBSD$

PORTNAME=	nspluginwrapper
PORTVERSION=	1.4.4
PORTREVISION=	5
CATEGORIES=	www linux emulators
MASTER_SITES=	http://nspluginwrapper.org/download/ \
		LOCAL/jkim \
		LOCAL/jkim:binfile
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${BINFILE}:binfile

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Compatibility plugin for Mozilla NPAPI plugins

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl

CONFLICTS=	nspluginwrapper-1.3.*

BINBUILD=	1
BINFILE=	${PORTNAME}-i386-${PORTVERSION}-${BINBUILD}${EXTRACT_SUFX}

ONLY_FOR_ARCHS=	i386 amd64

HAS_CONFIGURE=	yes
USE_GNOME=	glib20 gtk20
USE_LDCONFIG=	yes
USE_LINUX=	yes
USE_LINUX_APPS=	gtk2
USE_XORG=	x11 xext xt
USES=		gmake pkgconfig

CFLAGS+=	-std=c99

CONFIGURE_ARGS=	--enable-generic --enable-strip --prefix=${PREFIX} \
		--target-os=linux --target-cpu=i386 \
		--with-cc=${CC} --with-cxx=${CXX}

LIBDIR=		${PREFIX}/lib/${PORTNAME}
LINUX_BINDIR=	usr/lib/nspluginwrapper/i386/linux

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
	${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},g' \
	    ${WRKSRC}/src/npw-config.c
	${REINPLACE_CMD} -e 's,A-Z,:upper:,g; s,a-z,:lower:,g' \
	    ${WRKSRC}/configure ${WRKSRC}/src/npw-viewer.sh

post-install:
	${MKDIR} ${STAGEDIR}${LIBDIR}/i386/linux
	${INSTALL_PROGRAM} ${WRKDIR}/${LINUX_BINDIR}/*.bin \
	    ${WRKDIR}/${LINUX_BINDIR}/*.so ${STAGEDIR}${LIBDIR}/i386/linux/
	${INSTALL_SCRIPT} ${WRKDIR}/npviewer ${STAGEDIR}${LIBDIR}/i386/linux/

.include <bsd.port.post.mk>
