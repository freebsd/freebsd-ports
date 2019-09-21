# Created by: RaRa Rasputin <rasputin@submonkey.net>
# $FreeBSD$

PORTNAME=	steghide
PORTVERSION=	0.5.1
PORTREVISION=	7
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Steganography tool to hide data in binary files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmcrypt.so:security/libmcrypt \
		libmhash.so:security/mhash

USES=		compiler gmake jpeg libtool:build localbase perl5
GNU_CONFIGURE=	yes
CPPFLAGS+=	-fpermissive
LIBS+=		-lmcrypt
CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-static-float-init
MAKE_ARGS=	LIBTOOL="${LOCALBASE}/bin/libtool"

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls
NLS_LIBS=	-lintl

post-patch:
	@${REINPLACE_CMD} '/CXXFLAGS=/s|-O2|${CXXFLAGS}|' ${WRKSRC}/configure

.include <bsd.port.mk>
