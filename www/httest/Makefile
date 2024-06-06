PORTNAME=	httest
PORTVERSION=	2.4.24
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF/htt/htt${PORTVERSION:R}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTTP Test Tool
WWW=		https://htt.sourceforge.net/

LICENSE=	APACHE20

DEPRECATED=	Abandonware, no activity from upstream for years and depends on deprecated library devel/pcre
EXPIRATION_DATE=2024-06-30

BUILD_DEPENDS=	help2man:misc/help2man
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libgdbm.so:databases/gdbm \
		libpcre.so:devel/pcre \
		libapr-1.so:devel/apr1

USES=		iconv lua:-52 libtool ssl
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LUA_INCDIR}
LDFLAGS+=	-Wl,--as-needed


INSTALL_TARGET=		install-strip
MAKE_JOBS_UNSAFE=	yes
PORTEXAMPLES=		*

CONFIGURE_ARGS=	--enable-lua-module \
		--with-apr="${LOCALBASE}/bin" \
		--with-apr-util="${LOCALBASE}/bin" \
		--with-lua="${LUA_LIBDIR}" \
		--with-pcre="${LOCALBASE}/bin" \
		--with-ssl="${OPENSSLLIB}"

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|`$$APR_CONFIG --cflags`||; s|-llua|-llua-${LUA_VER}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' ${WRKSRC}/generate_modules_c.sh
	@${REINPLACE_CMD} -e 's|^apr_time_t start_time|extern &|' \
		${WRKSRC}/src/perf_module.c

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.htt ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
