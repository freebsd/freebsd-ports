# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	httest
PORTVERSION=	2.4.24
CATEGORIES=	www
MASTER_SITES=	SF/htt/htt${PORTVERSION:R}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTTP Test Tool

LICENSE=	APACHE20

BUILD_DEPENDS=	help2man:misc/help2man
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libgdbm.so:databases/gdbm \
		libpcre.so:devel/pcre \
		libapr-1.so:devel/apr1

USES=		iconv lua libtool bdb ssl
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	EXAMPLES

CONFIGURE_ARGS=	--enable-lua-module \
		--with-apr="${LOCALBASE}/bin" \
		--with-apr-util="${LOCALBASE}/bin" \
		--with-lua="${LUA_LIBDIR}" \
		--with-pcre="${LOCALBASE}/bin" \
		--with-ssl="${OPENSSLLIB}"
CPPFLAGS+=	-I${LUA_INCDIR}

PORTEXAMPLES=	*

INSTALL_TARGET=	install-strip

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1200085 && ${SSL_DEFAULT} == base
BROKEN=	requires OpenSSL 1.1.1, upgrade to FreeBSD 12.x/13.x or add DEFAULT_VERSIONS+=ssl=openssl to /etc/make.conf
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|`$$APR_CONFIG --cflags`||; s|-llua|-llua-${LUA_VER}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' ${WRKSRC}/generate_modules_c.sh
	@${REINPLACE_CMD} -e 's|^apr_time_t start_time|extern &|' \
		${WRKSRC}/src/perf_module.c

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.htt ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
