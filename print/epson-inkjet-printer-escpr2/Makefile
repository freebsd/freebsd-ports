PORTNAME=	epson-inkjet-printer-escpr2
DISTVERSION=	1.1.62
DISTVERSIONSUFFIX=	-1lsb3.2
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	https://download3.ebz.epson.net/dsc/f/03/00/14/47/10/b9bc8fe2cd3b8e463afa21598b27f2d264723e6e/:i386 \
		https://download3.ebz.epson.net/dsc/f/03/00/14/47/10/c4d50ad4c82cd65680d65a76ddde83a4fcae9b73/:amd64 \
		https://download3.ebz.epson.net/dsc/f/03/00/14/47/10/84d0ad36f1333fb1cae822976df1f611b7c2f6a0/:SOURCE
EXTRACT_SUFX=	.rpm
DISTFILES_amd64=	${DISTNAME}.x86_64${EXTRACT_SUFX}:amd64 \
			${_SRC_DISTFILES}
DISTFILES_i386=	${DISTNAME}.i486${EXTRACT_SUFX}:i386 \
		${_SRC_DISTFILES}

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	Epson Inkjet Printer Driver 2 (ESC/P-R) for Linux
WWW=		https://download.ebz.epson.net/dsc/search/01/search/?OSC=LX

LICENSE=	EPSON LGPL21
LICENSE_COMB=	multi
LICENSE_NAME_EPSON=	SEIKO EPSON CORPORATION SOFTWARE LICENSE AGREEMENT
LICENSE_FILE_EPSON=	${WRKSRC}/${PORTNAME}-${DISTVERSION}/COPYING.EPSON
LICENSE_FILE_LGPL21=	${WRKSRC}/${PORTNAME}-${DISTVERSION}/COPYING.LIB
LICENSE_PERMS_EPSON=		no-dist-mirror no-dist-sell no-pkg-mirror \
				no-pkg-sell
LICENSE_DISTFILES_EPSON=	${DISTNAME}.i486${EXTRACT_SUFX} \
				${DISTNAME}.x86_64${EXTRACT_SUFX} \
				${DISTNAME}.src${EXTRACT_SUFX}

LEGAL_TEXT=	License does not permit public sharing and revenue earning, and restricts exports
ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	${PORTNAME} for ARM is available. But binaries that can be used on aarch64 need to be built.

BUILD_DEPENDS=	patchelf:sysutils/patchelf
RUN_DEPENDS=	${LOCALBASE}/libexec/cups/filter/gstoraster:print/cups-filters \
		cupsfilter:print/cups

USES=		linux
USE_LDCONFIG=	yes
USE_LINUX=	cups-libs
_SRC_DISTFILES=	${DISTNAME}.src${EXTRACT_SUFX}:SOURCE
NO_BUILD=	yes
# PORTSCOUT=ignore:1 MASTER_SITES is changed in each version
PORTSCOUT=	ignore:1
NO_WRKSUBDIR=	yes
PLIST_SUB=	LINUXBASE=${LINUXBASE}

.include <bsd.port.options.mk>

.if ${ARCH} == amd64
PLIST_SUB+=	ARCH_AMD64="" \
		ARCH_I386="@comment "
.elif ${ARCH} == i386
PLIST_SUB+=	ARCH_AMD64="@comment " \
		ARCH_I386=""
.endif

post-extract:
	(cd ${EXTRACT_WRKDIR} && \
		${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTNAME}.tar.gz \
		${EXTRACT_AFTER_ARGS} -- ${PORTNAME}-${DISTVERSION}/COPYING.\*)
	${FIND} -- ${WRKSRC}/opt/${PORTNAME}/ppds/Epson -iname \*.ppd.gz \
		-exec ${GUNZIP_CMD} -- {} +

post-patch:
	${FIND} -- ${WRKSRC}/opt/${PORTNAME}/ppds/Epson -iname \*.ppd \
		-exec ${SED} -i '' -e '/^\*cupsFilter:/s,/opt/${PORTNAME}/,${LINUXBASE}&,' -- {} \; \
		-exec ${GZIP_CMD} -- {} \;

do-install:
	(cd ${WRKSRC} && \
		${FIND} opt | ${CPIO} -dumpl --quiet ${STAGEDIR}${LINUXBASE})
	${MKDIR} ${STAGEDIR}${PREFIX}/share/cups/model
	${RLN} ${STAGEDIR}${LINUXBASE}/opt/${PORTNAME}/ppds/Epson \
		${STAGEDIR}${PREFIX}/share/cups/model/${PORTNAME}
	patchelf --no-sort --set-interpreter /lib64/ld-linux-x86-64.so.2 \
		${WRKSRC}/opt/epson-inkjet-printer-escpr2/cups/lib/filter/epson-escpr-wrapper2
	patchelf --no-sort --set-interpreter /lib64/ld-linux-x86-64.so.2 \
		${WRKSRC}/opt/epson-inkjet-printer-escpr2/cups/lib/filter/epson-escpr2

.include <bsd.port.mk>
