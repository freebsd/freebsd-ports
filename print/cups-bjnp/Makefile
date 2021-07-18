PORTNAME=	cups-bjnp
PORTVERSION=	2.0.3
CATEGORIES=	print
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CUPS backend for Canon USB over IP protocol

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcups.so:print/cups

USES=		compiler:c11 localbase:ldflags

PLIST_FILES=	libexec/cups/backend/bjnp

GNU_CONFIGURE=	yes
# Just to avoid a tautological pointer compare in bjnp-commands.c:187
CONFIGURE_ARGS+=	--disable-Werror

.include <bsd.port.mk>
