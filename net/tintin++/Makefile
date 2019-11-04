# Created by: ache
# $FreeBSD$

PORTNAME=	tintin++
PORTVERSION=	2.01.92
CATEGORIES+=	net games
MASTER_SITES=	SF/tintin/TinTin%2B%2B%20Source%20Code/${PORTVERSION:C|.$||}/
DISTNAME=	tintin-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Client program to help playing MUDs

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

LIB_DEPENDS=	libpcre.so:devel/pcre

CONFLICTS_INSTALL?=	zh-tintin++

OPTIONS_DEFINE=	BIG5 DOCS
BIG5_DESC=	Big5 support

USES=		gmake localbase

CONFIGURE_ARGS=	--includedir=${LOCALBASE}/include \
		--libdir=${LOCALBASE}/lib \
		--prefix=${PREFIX}
CONFIGURE_ENV=	ac_cv_file__dev_ptmx=no \
		ac_cv_header_gnutls_gnutls_h=no \
		ac_cv_lib_gnutls_gnutls_init=no
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/tt/src

DOCS=		CREDITS FAQ README SCRIPTS TODO \
		docs/chat_protocol.txt docs/tintin19.txt
PLIST_FILES=	bin/tt++
PORTDOCS=	${DOCS:T}

SLAVEDIRS=	chinese/tintin++

BIG5_CONFIGURE_ENABLE=	big5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tt++ ${STAGEDIR}${PREFIX}/bin/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/../ && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
