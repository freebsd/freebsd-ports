PORTNAME=	epson-inkjet-printer-201401w
PORTVERSION=	1.0.0
CATEGORIES=	print
MASTER_SITES=	https://download3.ebz.epson.net/dsc/f/03/00/03/45/41/d95c03482376873661d7a8d4c165b385cd082cf3/:amd64 \
		https://download3.ebz.epson.net/dsc/f/03/00/03/45/41/0c527f1eef727e350302db951a45d31319ee501b/:i386
DISTFILES_amd64=${DISTNAME}-1lsb3.2.x86_64.rpm:amd64
DISTFILES_i386=	${DISTNAME}-1lsb3.2.i486.rpm:i386

MAINTAINER=	hello@blubee.me
COMMENT=	CUPS filter for Seiko Epson Color Ink Jet Printers

# License does not allow redistribution
LICENSE=		EPSON LGPL21
LICENSE_COMB=		multi
LICENSE_NAME_EPSON=	SEIKO EPSON CORPORATION SOFTWARE LICENSE AGREEMENT
LICENSE_FILE_EPSON=	${WRKSRC}/opt/${PORTNAME}/doc/COPYING.EPSON
LICENSE_FILE_LGPL21=	${WRKSRC}/opt/${PORTNAME}/doc/COPYING.LIB
LICENSE_PERMS_EPSON=	none

RUN_DEPENDS=	${LOCALBASE}/libexec/cups/filter/gstoraster:print/cups-filters

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_SUB=	LINUXBASE=${LINUXBASE} \
		PORTNAME=${PORTNAME}
USES=		linux
USE_LINUX=	cups-libs jpeg

.include <bsd.port.options.mk>

.if ${ARCH} == i386
PLIST_SUB+=	LIBDIR=lib
.elif ${ARCH} == amd64
PLIST_SUB+=	LIBDIR=lib64
.endif

post-extract:
	@${GUNZIP_CMD} ${WRKSRC}/opt/${PORTNAME}/ppds/Epson/*.ppd.gz

post-patch:
	@${SED} -i '' '/^\*cupsFilter:/s,/opt/,${LINUXBASE}&,' \
		${WRKSRC}/opt/${PORTNAME}/ppds/Epson/*.ppd

do-install:
	${MKDIR} ${STAGEDIR}${LINUXBASE}
	${CP} -Rp ${WRKSRC}/opt ${STAGEDIR}${LINUXBASE}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/cups/model/
	${LN} -sf ${LINUXBASE}/opt/${PORTNAME}/ppds/Epson ${STAGEDIR}${PREFIX}/share/cups/model/Epson-201401w

.include <bsd.port.mk>
