# New ports collection makefile for:	catdoc
# Date created:				11 November 1997
# Whom:					Brion Moss <brion@queeg.com>
#
# $FreeBSD$
#

PORTNAME=	catdoc
PORTVERSION=	0.94
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.45.free.net/pub/catdoc/
#		${MASTER_SITE_TEX_CTAN:S/$/support\/catdoc\//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert MS Word/Excel documents to plain ASCII or TeX.  TK viewer included

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
MAN1=		catdoc.1 wordview.1 xls2csv.1 catppt.1

.if !defined(LANG) || ${LANG} != ru_RU.KOI8-R
# Remove the below line to get Cyrillic code page support instead
CFLAGS+=	-DLATIN1=1
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/doc/catdoc.1.in

.include <bsd.port.pre.mk>

.for i in 0 1 2 3 4
.if exists(${LOCALBASE}/bin/wish8.${i})
CONFIGURE_ARGS=	--with-wish=${LOCALBASE}/bin/wish8.${i}
RUN_DEPENDS+=	${LOCALBASE}/bin/wish8.${i}:${PORTSDIR}/x11-toolkits/tk8${i}
.endif
.endfor

.include <bsd.port.post.mk>
