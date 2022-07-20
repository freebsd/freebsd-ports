PORTNAME=	libunibreak
PORTVERSION=	4.3
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/adah1972/${PORTNAME}/releases/download/${PORTNAME}_${PORTVERSION:C/\./_/}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of the line and word breaking algorithm for Unicode

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		libtool pathfix
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
MAKE_ARGS=	LN_S="${INSTALL_DATA}"

.include <bsd.port.mk>
