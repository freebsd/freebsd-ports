# Created by: RaRa Rasputin <rasputin@submonkey.net>
# $FreeBSD$

PORTNAME=	steghide
PORTVERSION=	0.5.1
PORTREVISION=	7
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Steganography tool to hide data in binary files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmcrypt.so:security/libmcrypt \
		libmhash.so:security/mhash

USES=		gmake jpeg libtool:build perl5
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -fpermissive
LIBS+=		-L${LOCALBASE}/lib -lmcrypt
MAKE_ARGS=	LIBTOOL="${LOCALBASE}/bin/libtool"

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
LIBS+=		-lintl
.endif

post-patch:
	@${REINPLACE_CMD} '/CXXFLAGS=/s|-O2|${CXXFLAGS}|' ${WRKSRC}/configure

.include <bsd.port.mk>
