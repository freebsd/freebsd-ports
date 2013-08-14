# Created by: kamikaze@bsdforen.de
# $FreeBSD$

PORTNAME=	libbluray
PORTVERSION=	0.2.2
PORTEPOCH=	1
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.videolan.org/pub/videolan/${PORTNAME}/${PORTVERSION}/ \
		http://blu.opsec.eu/

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	Blu-Ray discs playback library for media players

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2
# dlopen dependencies, libbdplus not yet available
LIB_DEPENDS+=	aacs.1:${PORTSDIR}/multimedia/libaacs

USES=		iconv
USE_LDCONFIG=	yes
USE_BZIP2=	yes
USE_AUTOTOOLS=	autoconf aclocal automake libtool

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix="${PREFIX}" \
		--disable-debug \
		--disable-optimizations
MAKE_ARGS+=	pkgconfigdir="${PREFIX}/libdata/pkgconfig" \
		CFLAGS=${CFLAGS:Q}

OPTIONS_DEFINE=	JAVA
JAVA_DESC=	Enable Blu-Ray Java support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJAVA}
BUILD_DEPENDS+=	ant:${PORTSDIR}/devel/apache-ant
CATEGORIES+=	java
USE_JAVA=	1.6+
JAVA_BUILD=	yes
JAVA_RUN=	yes
CONFIGURE_ARGS+=	--enable-bdjava \
		--with-jdk="${JAVA_HOME}"
.endif

run-autotools:
	@cd ${WRKSRC} && ${SH} bootstrap

plist: build
	@${ECHO} "===> Rebuilding PLIST."
	@${MKDIR} "${WRKDIR}/plist"
	@cd ${WRKSRC} && ( \
		${SETENV} ${CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS} --prefix="${WRKDIR}/plist" && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} pkgconfigdir="${WRKDIR}/plist/libdata/pkgconfig" ${INSTALL_TARGET} ; \
		${SETENV} ${CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS} \
	)
	@${FIND} -ds "${WRKDIR}/plist/" -not -type d \
		| ${SED} "s|${WRKDIR}/plist/||1" > ${PLIST}
	@${FIND} -ds "${WRKDIR}/plist/" -type d -mindepth 2 \
		| ${SED} -e "/pkgconfig/d" -e "s|${WRKDIR}/plist/|@dirrm |1" >> ${PLIST}
	@${RM} -rf "${WRKDIR}/plist"

.include <bsd.port.mk>
