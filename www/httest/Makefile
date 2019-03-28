# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	httest
PORTVERSION=	2.4.23
PORTREVISION=	3
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

# Reported upstream:
# https://sourceforge.net/p/htt/tickets/5/

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200085
BROKEN=		does not build with OpenSSL 1.1.1
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|`$$APR_CONFIG --cflags`||; s|-llua|-llua-${LUA_VER}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' ${WRKSRC}/generate_modules_c.sh
	@${REINPLACE_CMD} -e 's|<pcre/pcre.h>|<pcre.h>|' ${WRKSRC}/src/httest.c ${WRKSRC}/src/regex.c \
		${WRKSRC}/src/body.c ${WRKSRC}/src/module.h ${WRKSRC}/src/worker.c

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.htt ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
