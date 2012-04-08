# New ports collection makefile for:	httest
# Date created:			Jun 15, 2011
# Whom:				Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	httest
PORTVERSION=	2.1.18
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/htt/htt${PORTVERSION:R}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTTP Test Tool

LICENSE=	AL2

LIB_DEPENDS=	apr-1.4:${PORTSDIR}/devel/apr1 \
		pcre.1:${PORTSDIR}/devel/pcre

USE_LUA=	yes
USE_OPENSSL=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-apr="${LOCALBASE}/bin" \
		--with-apr-util="${LOCALBASE}/bin" \
		--with-pcre="${LOCALBASE}/bin" \
		--with-ssl="${OPENSSLLIB}" \
		--with-lua="${LUA_LIBDIR}" \
		--enable-lua-module
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LUA_INCDIR}

MAN1=		httest.1 htproxy.1 htntlm.1 htremote.1
PORTEXAMPLES=	*
PLIST_FILES=	bin/htntlm bin/htproxy bin/htremote bin/httest bin/hturlext \
		bin/htx2b

post-patch:
	@${REINPLACE_CMD} -e \
		's|`$$APR_CONFIG --cflags`||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|/bin/bash|/bin/sh|' ${WRKSRC}/generate_modules_c.sh

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.htt ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
