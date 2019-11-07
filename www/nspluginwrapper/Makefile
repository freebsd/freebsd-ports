# Created by: Dave Grochowski
# $FreeBSD$

PORTNAME=	nspluginwrapper
PORTVERSION=	1.4.4
PORTREVISION=	7
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
USES=		gmake gnome linux pkgconfig xorg
USE_GNOME=	glib20 gtk20
USE_LDCONFIG=	yes
USE_LINUX=	gtk2
USE_XORG=	x11 xext xt

CFLAGS+=	-std=c99

CONFIGURE_ARGS=	--enable-generic --enable-strip --prefix=${PREFIX} \
		--target-cpu=i386 --target-os=linux \
		--with-cc=${CC} --with-cxx=${CXX}

LIBDIR=		${PREFIX}/lib/${PORTNAME}
LINUX_BINDIR=	usr/lib/nspluginwrapper/i386/linux

PLIST_SUB=	HOST_ARCH="${ARCH:S/amd64/x86_64/}" \
		LIBDIR="${LIBDIR:C/^${PREFIX}\///}"

SUB_FILES=	npviewer
SUB_LIST=	NSPLUGINWRAPPER="${LIBDIR}"

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

.include <bsd.port.mk>
