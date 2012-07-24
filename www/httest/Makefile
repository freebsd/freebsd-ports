# New ports collection makefile for:	httest
# Date created:			Jun 15, 2011
# Whom:				Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	httest
PORTVERSION=	2.2.7
CATEGORIES=	www
MASTER_SITES=	SF/htt/htt${PORTVERSION:R}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTTP Test Tool

LICENSE=	AL2

LIB_DEPENDS=	apr-1:${PORTSDIR}/devel/apr1 \
		pcre:${PORTSDIR}/devel/pcre

OPTIONS_DEFINE=	EXAMPLES

CONFIGURE_ARGS=	--enable-lua-module \
		--with-apr="${LOCALBASE}/bin" \
		--with-apr-util="${LOCALBASE}/bin" \
		--with-lua="${LUA_LIBDIR}" \
		--with-pcre="${LOCALBASE}/bin" \
		--with-ssl="${OPENSSLLIB}"
CPPFLAGS+=	-I${LUA_INCDIR}
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
USE_ICONV=	yes
USE_LUA=	yes
USE_OPENSSL=	yes

MAN1=		htntlm.1 htproxy.1 htremote.1 httest.1 hturlext.1 htx2b.1
PLIST_FILES=	bin/htntlm bin/htproxy bin/htremote bin/httest bin/hturlext bin/htx2b
PORTEXAMPLES=	*

post-patch:
	@${REINPLACE_CMD} -e 's|`$$APR_CONFIG --cflags`||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' ${WRKSRC}/generate_modules_c.sh

.include <bsd.port.options.mk>

.if ${OSVERSION} < 800000 && ${ARCH} == "amd64"
BROKEN=		does not compile on 7.X/amd64
.endif

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/examples/*.htt ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
