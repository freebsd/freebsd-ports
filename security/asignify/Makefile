PORTNAME=	asignify
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://highsecure.ru/distfiles/

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Yet another signify tool
WWW=		https://github.com/vstakhov/asignify/

LICENSE=	BSD2CLAUSE

USES=		autoreconf tar:xz libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -E 's|BLAKE_ALIGN\( 64 \) typedef struct __blake2b_state|typedef struct BLAKE_ALIGN\( 64 \) __blake2b_state|g' \
		${WRKSRC}/libasignify/blake2.h

.include <bsd.port.mk>
