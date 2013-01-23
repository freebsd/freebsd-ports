# New ports collection makefile for:	netsurf
# Date created:		17 August 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	netsurf
PORTVERSION=	2.9
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.netsurf-browser.org/projects/releases/ \
		http://www.netsurf-browser.org/downloads/releases/:netsurf
DISTFILES=	${WAPCAPLET_DISTNAME}${EXTRACT_SUFX} \
		${HUBBUB_DISTNAME}${EXTRACT_SUFX} \
		${CSS_DISTNAME}${EXTRACT_SUFX} \
		${NSBMP_DISTNAME}${EXTRACT_SUFX} \
		${NSGIF_DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-${PORTVERSION}-src${EXTRACT_SUFX}:netsurf
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	A lightweight web browser

LICENSE=	GPLv2 MIT
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/lib/libparserutils.a:${PORTSDIR}/devel/libparserutils
LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		lcms.1:${PORTSDIR}/graphics/lcms \
		mng.1:${PORTSDIR}/graphics/libmng

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GNOME=	libglade2 librsvg2 libxml2
USE_GMAKE=	yes
CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV=	PKG_CONFIG_PATH="${WRKDIR}/fakeroot/lib/pkgconfig:${LOCALBASE}/libdata/pkgconfig"
MAKE_ARGS=	HOST_CC="${CC}" CC="${CC}" CCOPT="" HOST="${OPSYS}" \
		WARNFLAGS="${CFLAGS}" Q=""
MAKE_JOBS_SAFE=	yes

DESKTOP_ENTRIES="NetSurf" "${COMMENT}" "" "${PORTNAME}" "" "true"

WAPCAPLET_DISTNAME=	libwapcaplet-0.1.1-src
HUBBUB_DISTNAME=	hubbub-0.1.2-src
CSS_DISTNAME=		libcss-0.1.2-src
NSBMP_DISTNAME=		libnsbmp-0.0.3-src
NSGIF_DISTNAME=		libnsgif-0.0.3-src

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's| -O2 | |' ${WRKSRC}/Makefile.defaults
	@${REINPLACE_CMD} -e \
		's| -g | |' ${WRKSRC}/gtk/Makefile.target
	@${REINPLACE_CMD} -e '/ifeq.*clang/s/word 1/filter clang/' \
		${WRKDIR}/*/build/makefiles/Makefile.tools

do-configure:
	@${TOUCH} ${WRKSRC}/Makefile.config
	@${ECHO_CMD} 'NETSURF_USE_HARU_PDF=NO' >> ${WRKSRC}/Makefile.config
	@${ECHO_CMD} 'NETSURF_USE_LIBICONV_PLUG=NO' >> ${WRKSRC}/Makefile.config
	@${ECHO_CMD} 'NETSURF_USE_NSSVG=NO' >> ${WRKSRC}/Makefile.config
	@${ECHO_CMD} 'NETSURF_USE_ROSPRITE=NO' >> ${WRKSRC}/Makefile.config
	@${ECHO_CMD} 'NETSURF_USE_WEBP=NO' >> ${WRKSRC}/Makefile.config

pre-build:
	@${MKDIR} ${WRKDIR}/fakeroot
.for dir in ${WAPCAPLET_DISTNAME:S/-src//} ${HUBBUB_DISTNAME:S/-src//} \
		${CSS_DISTNAME:S/-src//} ${NSBMP_DISTNAME} ${NSGIF_DISTNAME}
	@${MAKE_ENV} ${GMAKE} -C${WRKDIR}/${dir} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} \
		${MAKE_ARGS} ${INSTALL_TARGET} PREFIX="${WRKDIR}/fakeroot"
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nsgtk ${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${DATADIR}
	@(${TAR} --exclude "C" --exclude "*.glade" -C ${WRKSRC}/gtk/res \
		-L -cf - . | ${TAR} -C ${DATADIR} --unlink -xf -)
	@${LN} -sf en ${DATADIR}/C
	@(cd ${WRKSRC}/gtk/res ; \
		for i in `${LS} -d *.glade` ; do \
			 ${CAT} $$i | ${GZIP_CMD} > ${DATADIR}/$$i ; \
		done)
	@${FIND} ${DATADIR} | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@${FIND} ${DATADIR} -type d | ${XARGS} ${CHMOD} a+rx
	@${FIND} ${DATADIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
