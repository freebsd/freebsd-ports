# Created by: chinsan
# $FreeBSD$

PORTNAME=	odt2txt
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	GH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple converter from OpenDocument Text to plain text

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	dstosberg
GH_PROJECT=	odt2txt
GH_COMMIT=	97b8999
GH_TAGNAME=	${GH_COMMIT}
USES=		iconv gmake

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/odt2txt man/man1/odt2txt.1.gz

post-patch:
	${REINPLACE_CMD} -e 's#/usr/local#${LOCALBASE}#g' \
		-e 's#-liconv#${ICONV_LIB}#' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/odt2txt ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/odt2txt.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
