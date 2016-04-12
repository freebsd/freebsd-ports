# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	httest
PORTVERSION=	2.4.16
CATEGORIES=	www
MASTER_SITES=	SF/htt/htt${PORTVERSION:R}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	HTTP Test Tool

LICENSE=	APACHE20

LIB_DEPENDS=	libapr-1.so:devel/apr1 \
		libpcre.so:devel/pcre

OPTIONS_DEFINE=	EXAMPLES

CONFIGURE_ARGS=	--enable-lua-module \
		--with-apr="${LOCALBASE}/bin" \
		--with-apr-util="${LOCALBASE}/bin" \
		--with-lua="${LUA_LIBDIR}" \
		--with-pcre="${LOCALBASE}/bin" \
		--with-ssl="${OPENSSLLIB}"
CPPFLAGS+=	-I${LUA_INCDIR}
GNU_CONFIGURE=	yes
USES=		iconv lua libtool
USE_OPENSSL=	yes
USE_LDCONFIG=	yes

PORTEXAMPLES=	*

INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|`$$APR_CONFIG --cflags`||; s|-llua|-llua-${LUA_VER}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' ${WRKSRC}/generate_modules_c.sh

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.htt ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
