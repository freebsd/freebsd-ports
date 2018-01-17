# $FreeBSD$

PORTNAME=	htmlcxx
PORTVERSION=	0.86
CATEGORIES=	www textproc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTML and CSS APIs for C++

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/LGPL_V2

USES=		bison iconv libtool pathfix
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} 's/-liconv/${ICONV_LIB}/' ${WRKSRC}/configure

.include <bsd.port.mk>
