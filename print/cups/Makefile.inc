# Common file for CUPS ports
# $FreeBSD$

MASTER_SITES=	\
		ftp://ftp.funet.fi/pub/mirrors/ftp.easysw.com/pub/cups/${CUPS_VERSION}/ \
		ftp://ftp.ntua.gr/pub/gnu/cups/${CUPS_VERSION}/ \
		ftp://ftp.easysw.com/pub/cups/${CUPS_VERSION}/ \
		ftp://ftp.fisek.com.tr/pub/cups/${CUPS_VERSION}/ \
		ftp://ftp.mpg.goe.ni.schule.de/pub/internet/printing/cups/${CUPS_VERSION}/

CUPS_VERSION=	1.1.15
CUPS_REVISION=	1
CUPS_PORTVER=	${CUPS_VERSION}.${CUPS_REVISION}

.ifdef CUPS_FR
MANLANG=	"" fr
.else
EXTRA_PATCHES=${.CURDIR}/../../print/cups/files/fr-patch-man-Makefile
.endif

EXTRA_PATCHES+=${.CURDIR}/../../print/cups/files/patch-man-Makefile
EXTRA_PATCHES+=${.CURDIR}/../../print/cups/files/patch-man-fr-Makefile
EXTRA_PATCHES+=${.CURDIR}/../../print/cups/files/patch-config-scripts-cups-common.m4
EXTRA_PATCHES+=${.CURDIR}/../../print/cups/files/patch-Makedefs.in

#protect the base port
.if ${PORTNAME} != "cups"
DISTNAME=	cups-${CUPS_VERSION}-${CUPS_REVISION}-source
#DISTNAME=	cups-${CUPS_VERSION}-source
DISTFILES=	${DISTNAME}.tar.bz2
WRKSRC=		${WRKDIR}/cups-${CUPS_VERSION}

USE_PERL5=	yes
USE_BZIP2=	yes
#Breaks build.. USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	CFLAGS="${CFLAGS}"
CONFIGURE_ENV+=	CPPFLAGS="-I${PREFIX}/include"
CONFIGURE_ENV+=	DSOFLAGS="-L${PREFIX}/lib"
CONFIGURE_ENV+=	LDFLAGS="-L${PREFIX}/lib"

CONFIGURE_ARGS+= --localstatedir=/var

AUTOCONF=	autoconf
BUILD_DEPENDS+=	autoconf:${PORTSDIR}/devel/autoconf

LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

post-patch::
	cd ${WRKSRC}; ${AUTOCONF} --force
.endif

