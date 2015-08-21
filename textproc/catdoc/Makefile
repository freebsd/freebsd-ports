# Created by: Brion Moss <brion@queeg.com>
# $FreeBSD$

PORTNAME=	catdoc
PORTVERSION=	0.94.2
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/ \
		LOCAL/amdmi3 \
		ftp://ftp.dvo.ru/pub/Gentoo/distfiles/ \
		ftp://ftp.demos.ru/pub/sunfreeware/SOURCES/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	MS Word/Excel converter to plain ASCII or TeX. TK viewer included

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-install-root="${STAGEDIR}"
USES=		gmake

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
