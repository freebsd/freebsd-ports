# Created by: kamikaze@bsdforen.de
# $FreeBSD$

PORTNAME=	libbluray
PORTVERSION=	0.3.0
PORTEPOCH=	1
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.videolan.org/pub/videolan/${PORTNAME}/${PORTVERSION}/ \
		http://blu.opsec.eu/

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	Blu-Ray discs playback library for media players

LICENSE=	LGPL21

LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2
# dlopen dependencies, libbdplus not yet available
LIB_DEPENDS+=	libaacs.so:${PORTSDIR}/multimedia/libaacs

USES=		iconv pkgconfig
USE_LDCONFIG=	yes
USE_BZIP2=	yes
USE_AUTOTOOLS=	autoconf aclocal automake libtool

HAS_CONFIGURE=	yes
MAKE_ARGS=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"
CONFIGURE_ARGS=	--prefix="${PREFIX}" \
		--disable-debug

OPTIONS_DEFINE=	JAVA
JAVA_DESC=	Enable Blu-Ray Java support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJAVA}
BROKEN=		Does not build with JAVA
BUILD_DEPENDS+=	ant:${PORTSDIR}/devel/apache-ant
CATEGORIES+=	java
USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_BUILD=	yes
JAVA_RUN=	yes
CONFIGURE_ARGS+=	--enable-bdjava --with-bdj-type=j2se
CONFIGURE_ENV+=	JDK_HOME="${JAVA_HOME}"
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
