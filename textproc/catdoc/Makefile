PORTNAME=	catdoc
PORTVERSION=	0.95
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://ftp.wagner.pp.ru/pub/catdoc/ \
		https://mirror.amdmi3.ru/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MS Word/Excel converter to plain ASCII or TeX. TK viewer included
WWW=		https://www.wagner.pp.ru/~vitus/software/catdoc/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe gmake
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--with-install-root="${STAGEDIR}"
CPE_VENDOR=	fossies

CONFLICTS_INSTALL=	libxls p5-Spreadsheet-Read xls2txt

PORTDATA=	*

OPTIONS_DEFINE=	WORDVIEW
OPTIONS_DEFAULT=WORDVIEW
OPTIONS_SUB=	yes

WORDVIEW_DESC=	Build Tcl/Tk document viewer

WORDVIEW_USES=	tk
WORDVIEW_CONFIGURE_ON=	--with-wish=${WISH}
WORDVIEW_CONFIGURE_OFF=	--disable-wordview

.if !defined(LANG) || ${LANG} != ru_RU.KOI8-R
# Remove the below line to get Cyrillic code page support instead
CFLAGS+=	-DLATIN1=1
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/doc/catdoc.1.in

post-install:
	cd ${STAGEDIR}${PREFIX}/bin && ${STRIP_CMD} catdoc catppt xls2csv

.include <bsd.port.mk>
