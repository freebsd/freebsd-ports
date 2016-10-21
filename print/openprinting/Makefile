# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openprinting
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	print net
MASTER_SITES=	SF/openprinting/papi/1.0%20Beta
DISTNAME=	papi-${PORTVERSION}_beta
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sun's implementation of the OpenPrinting API (PAPI)

WRKSRC=		${WRKDIR}/papi-${PORTVERSION}_beta

USES=		gettext gmake iconv libtool tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lintl

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

# NOTE: This has only been tested with www/apache20, with integrated APR.
.if defined(WITH_MOD_IPP)
IGNORE=	no supported apache versions available
#USE_APACHE=	20
#CONFIGURE_ARGS+=--with-apache=${LOCALBASE}
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
	man/man5/psm-ipp.5.gz

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
.for unneeded in bin sbin man/man1 man/mani share
	@${RM} -r ${STAGEDIR}${PREFIX}/${unneeded}
.endfor

.include <bsd.port.mk>
