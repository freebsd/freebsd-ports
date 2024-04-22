PORTNAME=	openprinting
PORTVERSION=	1.0
PORTREVISION=	6
CATEGORIES=	print net
MASTER_SITES=	SF/openprinting/papi/1.0%20Beta
DISTNAME=	papi-${PORTVERSION}_beta
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sun's implementation of the OpenPrinting API (PAPI)
WWW=		https://openprinting.sourceforge.net/

USES=		gettext gmake iconv libtool localbase tar:bzip2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	install-strip

WRKSRC=		${WRKDIR}/papi-${PORTVERSION}_beta

LIBS+=		-lintl
LLD_UNSAFE=	yes

# TODO: Get mod_ipp to actually work; Sun's example seems to be broken
# under both Apache 1.3/2.0, this could be a papi issue; does not build
# w/Apache 2.2.
# TODO: Fix Apache module install target to instead use APXS
# from this file; it is intended only as an example.
# TODO: CUPS integration is broken in distfiles (missing papi_int.h).
#OPTIONS=\
#	MOD_IPP		"Build example mod_ipp.so for Apache" Off
#	PSM_CUPS	"Build psm_cups.so for printing to CUPS" Off

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

# NOTE: This has only been tested with www/apache20, with integrated APR.
.if defined(WITH_MOD_IPP)
IGNORE=	no supported apache versions available
.else
CONFIGURE_ARGS+=--without-apache
.endif

.if defined(WITH_PSM_CUPS)
LIB_DEPENDS+=	libcups.so:print/cups
CONFIGURE_ARGS+=--with-cups=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-cups
.endif

PLIST_FILES+=\
	include/debug.h \
	include/http-private.h \
	include/http.h \
	include/ipp-listener.h \
	include/ipp.h \
	include/papi.h \
	lib/libipp-core.so \
	lib/libipp-core.so.0 \
	lib/libipp-core.so.0.0.0 \
	lib/libipp-listener.so \
	lib/libipp-listener.so.0 \
	lib/libipp-listener.so.0.0.0 \
	lib/libpapi-common.so \
	lib/libpapi-common.so.0 \
	lib/libpapi-common.so.0.0.0 \
	lib/libpapi.so \
	lib/libpapi.so.0 \
	lib/libpapi.so.0.0.0 \
	libexec/lpd-port \
	libexec/psm-ipp.so \
	libexec/psm-lpd.so \
	share/man/man5/psm-ipp.5.gz

.if defined(WITH_PSM_CUPS)
PLIST_FILES+=	libexec/psm-cups.so
.endif

.if defined(WITH_MOD_IPP)
PLIST_FILES+=	lib/mod_ipp.so
.endif

post-patch:
	@${REINPLACE_CMD} '/^LIBS =/s,$$, ../libpapi-common/libpapi-common.la @LIBS@,' \
		${WRKSRC}/source/bsd-sysv-commands/Makefile.in \
		${WRKSRC}/source/examples/Makefile.in
	@${REINPLACE_CMD} -e 's/-ldl//' -e 's/-lnsl//' \
		${WRKSRC}/source/libpapi-cups/Makefile.in \
		${WRKSRC}/source/libpapi-dynamic/Makefile.in

post-install:
.for unneeded in bin sbin share/examples share/man/man1 share/man/mani
	@${RM} -r ${STAGEDIR}${PREFIX}/${unneeded}
.endfor

.include <bsd.port.mk>
