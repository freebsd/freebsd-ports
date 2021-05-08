PORTNAME=	epson-inkjet-printer-escpr2
DISTVERSION=	1.1.32
DISTVERSIONSUFFIX=	-1lsb3.2
CATEGORIES=	print
MASTER_SITES=	https://download3.ebz.epson.net/dsc/f/03/00/12/70/11/b8158a7846302ab23bd5856b775e2ffc51edcd30/:i386 \
		https://download3.ebz.epson.net/dsc/f/03/00/12/70/11/059b05d1ec465fd50cefd9c2086ad81af1cfd48f/:amd64 \
		https://download3.ebz.epson.net/dsc/f/03/00/12/70/11/de9d464075fec36d939b42b5f127bcf550a5be07/:SOURCE

EXTRACT_SUFX=	.rpm
DISTFILES_amd64=	${DISTNAME}.x86_64${EXTRACT_SUFX}:amd64
DISTFILES_i386=	${DISTNAME}.i486${EXTRACT_SUFX}:i386
EXTRACT_ONLY=	${_DISTFILES}

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	Epson Inkjet Printer Driver 2 (ESC/P-R) for Linux

LICENSE=	EPSON LGPL21
LICENSE_COMB=	multi
LICENSE_NAME_EPSON=	SEIKO EPSON CORPORATION SOFTWARE LICENSE AGREEMENT
LICENSE_FILE_EPSON=	${WRKSRC}/${PKGNAME}/COPYING.EPSON
LICENSE_FILE_LGPL21=	${WRKSRC}/${PKGNAME}/COPYING.LIB
LICENSE_PERMS_EPSON=		no-dist-mirror no-dist-sell no-pkg-mirror \
				no-pkg-sell
LICENSE_DISTFILES_EPSON=	${DISTNAME}.x86_64${EXTRACT_SUFX} \
				${DISTNAME}.i486${EXTRACT_SUFX} \
				${DISTNAME}.src${EXTRACT_SUFX}

LEGAL_TEXT=	License does not permit public sharing and revenue earning, and restricts exports

RUN_DEPENDS=	${LOCALBASE}/libexec/cups/filter/gstoraster:print/cups-filters \
		cupsfilter:print/cups

USES=		linux
USE_LINUX=	cups-libs jpeg

SRC_DISTFILES=	${DISTNAME}.src${EXTRACT_SUFX}:SOURCE

NO_BUILD=	yes
# MASTER_SITES is changed in each version
PORTSCOUT=	ignore:1

NO_WRKSUBDIR=	yes

.include <bsd.port.options.mk>

PLIST_SUB=	LINUXBASE=${LINUXBASE} \
		PORTNAME=${PORTNAME}

.if ${ARCH} == amd64
PLIST_SUB+=	LIBDIR=lib64
.elif ${ARCH} == i386
PLIST_SUB+=	LIBDIR=lib
.endif

post-extract:
	(cd ${EXTRACT_WRKDIR} && \
		${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTNAME}.tar.gz \
		${EXTRACT_AFTER_ARGS} -- ${PKGNAME}/COPYING.\*)
	@${GUNZIP_CMD} ${WRKSRC}/opt/${PORTNAME}/ppds/Epson/*.ppd.gz

post-patch:
	@${SED} -i '' -e '/^\*cupsFilter:/s,/opt/${PORTNAME}/,${LINUXBASE}&,' \
		${WRKSRC}/opt/${PORTNAME}/ppds/Epson/*.ppd

do-install:
	(cd ${WRKSRC} && \
		${FIND} opt | ${CPIO} -dumpl --quiet ${STAGEDIR}${LINUXBASE})
	${MKDIR} ${STAGEDIR}${PREFIX}/share/cups/model
	${LN} -s -f ${LINUXBASE}/opt/${PORTNAME}/ppds/Epson \
		${STAGEDIR}${PREFIX}/share/cups/model/${PORTNAME}

.include <bsd.port.mk>
