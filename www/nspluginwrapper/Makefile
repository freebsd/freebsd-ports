# Created by: Dave Grochowski
# $FreeBSD$

PORTNAME=	nspluginwrapper
PORTVERSION=	1.4.4
PORTREVISION=	1
CATEGORIES=	www linux emulators
MASTER_SITES=	http://nspluginwrapper.org/download/ \
		LOCAL/jkim \
		LOCAL/jkim:binfile
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${BINFILE}:binfile

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	A compatibility plugin for Mozilla NPAPI plugins

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

CONFLICTS=	nspluginwrapper-1.3.*

BINBUILD=	1
BINFILE=	${PORTNAME}-i386-${PORTVERSION}-${BINBUILD}${EXTRACT_SUFX}

ONLY_FOR_ARCHS=	i386 amd64

USE_LINUX=	yes
USE_LINUX_APPS=	gtk2
USE_XORG=	x11 xext xt
USES=		pkgconfig
USE_GNOME=	glib20 gtk20

CFLAGS+=	-std=c99

USE_LDCONFIG=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--enable-generic --enable-strip --prefix=${PREFIX} \
		--target-os=linux --target-cpu=i386 \
		--with-cc=${CC} --with-cxx=${CXX}

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
	${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},g' \
	    ${WRKSRC}/src/npw-config.c
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/src/npruntime.c ${WRKSRC}/src/npw-player.c \
		${WRKSRC}/src/utils.c

post-install:
	${MKDIR} ${LIBDIR}/i386/linux
	${INSTALL_PROGRAM} ${WRKDIR}/usr/lib/nspluginwrapper/i386/linux/*.bin \
	    ${WRKDIR}/usr/lib/nspluginwrapper/i386/linux/*.so \
	    ${LIBDIR}/i386/linux/
	${INSTALL_SCRIPT} ${WRKDIR}/npviewer ${LIBDIR}/i386/linux/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
