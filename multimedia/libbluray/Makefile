# New ports collection makefile for:	libbluray
# Date created:	19 February 2011
# Whom:		kamikaze@bsdforen.de
#
# $FreeBSD$
#

PORTNAME=	libbluray
PORTVERSION=	0.2.20110219
CATEGORIES=	multimedia
MASTER_SITES=	CRITICAL

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	Blu-Ray discs playback library for media players

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2
# dlopen dependencies, libbdplus not yet available
LIB_DEPENDS+=	aacs.0:${PORTSDIR}/multimedia/libaacs

# libiconv.so.3
USE_ICONV=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf aclocal automake libtool

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix="${PREFIX}" \
		--disable-debug \
		--disable-optimizations
MAKE_JOBS_SAFE=	yes
MAKE_ARGS+=	pkgconfigdir="${PREFIX}/libdata/pkgconfig" \
		CFLAGS=${CFLAGS:Q}

OPTIONS=	JAVA "Enable Blu-Ray Java support" off

.include <bsd.port.options.mk>

.if defined(WITH_JAVA)
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
