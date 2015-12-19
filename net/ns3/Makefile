# $FreeBSD$

PORTNAME=	ns3
PORTVERSION=	3.24.1
CATEGORIES=	net
MASTER_SITES=	https://www.nsnam.org/release/
DISTNAME=	ns-allinone-${PORTVERSION}

MAINTAINER=	koue@chaosophia.net
COMMENT=	Network simulator for Internet systems

LICENSE=	GPLv2

LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2 \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3

USES=		pkgconfig python tar:bzip2
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DEBUG EXAMPLES GSL GTK SUDO TESTS
OPTIONS_DEFAULT=EXAMPLES TESTS

DEBUG_DESC=	Enable debug build profile
EXAMPLES_DESC=	Enable examples
GSL_DESC=	GSL support
GTK_DESC=	GTK support
SUDO_DESC=	Enable sudo support
TESTS_DESC=	Enable tests

BUILDARGS+=	--int64x64=cairo

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
BUILDARGS+=		-d debug
PLIST_SUB+=		WITH_DEBUG="-debug"
.else
BUILDARGS+=		-d release
PLIST_SUB+=		WITH_DEBUG=""
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
BUILDARGS+=		--enable-examples
PLIST_SUB+=		WITH_EXAMPLES=""
.else
BUILDARGS+=		--disable-examples
PLIST_SUB+=		WITH_EXAMPLES="@comment "
.endif

.if ${PORT_OPTIONS:MGSL}
LIB_DEPENDS+=		libgsl.so:${PORTSDIR}/math/gsl
.endif

.if ${PORT_OPTIONS:MGTK}
LIB_DEPENDS+=		libgtk-x11-2.0.so:${PORTSDIR}/x11-toolkits/gtk20
PLIST_SUB+=		WITH_GTK=""
.else
BUILDARGS+=		--disable-gtk
PLIST_SUB+=		WITH_GTK="@comment "
.endif

.if ${PORT_OPTIONS:MSUDO}
BUILDARGS+=		--enable-sudo
BUILD_DEPENDS+=		${LOCALBASE}/bin/sudo:${PORTSDIR}/security/sudo
.endif

.if ${PORT_OPTIONS:MTESTS}
BUILDARGS+=		--enable-tests
PLIST_SUB+=		WITH_TESTS=""
.else
BUILDARGS+=		--disable-tests
PLIST_SUB+=		WITH_TESTS="@comment "
.endif

do-configure:
	(cd ${WRKSRC}/ns-${PORTVERSION}/ && ${PYTHON_CMD} waf configure --prefix=${STAGEDIR}${PREFIX} ${BUILDARGS})

do-build:
	(cd ${WRKSRC}/ns-${PORTVERSION}/ && ${PYTHON_CMD} waf build)

do-install:
	(cd ${WRKSRC}/ns-${PORTVERSION}/ && ${PYTHON_CMD} waf install)

post-install-DEBUG-on:
	@cd ${STAGEDIR}${PREFIX}/bin; \
		for FILE in *debug; do \
			${STRIP_CMD} $${FILE}; \
		done

post-install:
	@cd ${STAGEDIR}${PREFIX}/bin; \
		for FILE in *; do \
			${STRIP_CMD} $${FILE}; \
		done
	@cd ${STAGEDIR}${PREFIX}/lib; \
		for FILE in *.so; do \
			${STRIP_CMD} $${FILE}; \
		done
	@cd ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/ns/; \
		for FILE in *.so; do \
			${STRIP_CMD} $${FILE}; \
		done
	@cd ${STAGEDIR}${PREFIX}/libdata/pkgconfig; \
		for FILE in *.pc; do \
			${REINPLACE_CMD} -e "s,${STAGEDIR},," $${FILE}; \
			${RM} -f $${FILE}.bak; \
		done
	${REINPLACE_CMD} -e "s,${STAGEDIR},," ${STAGEDIR}${PREFIX}/include/ns${PORTVERSION}/${PORTNAME}/config-store-config.h
	${RM} ${STAGEDIR}${PREFIX}/include/ns${PORTVERSION}/${PORTNAME}/config-store-config.h.bak

.include <bsd.port.mk>
