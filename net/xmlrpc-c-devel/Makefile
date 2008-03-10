# ex:ts=8
# New ports collection makefile for:	xmlrpc-c
# Date created:			Mar 8, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmlrpc-c
PORTVERSION=	1.06.24
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML-RPC library for C and C++

OPTIONS=	CURL "Compile with curl support" on \
		LIBWWW "Compile with libwww support" off

USE_AUTOTOOLS=	libtool:15:env
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PERL5=	yes
MAKEFILE=	GNUmakefile
MAKE_ENV+=	CFLAGS_FREEBSD="${CFLAGS}" \
		CXXFLAGS_FREEBSD="${CXXFLAGS}"

CONFLICTS=	xmlrpc-epi-0.*

.include <bsd.port.pre.mk>

.if defined(WITH_LIBWWW) || (!defined(WITHOUT_LIBWWW) && exists(${LOCALBASE}/lib/libwwwcore.so.1))
LIB_DEPENDS+=	wwwcore.1:${PORTSDIR}/www/libwww
OPT_LIBWWW=	yes
.else
CONFIGURE_ARGS+=	--disable-libwww-client
.endif

.if !defined(WITHOUT_CURL)
LIB_DEPENDS+=	curl.4:${PORTSDIR}/ftp/curl
OPT_CURL=	yes
.else
CONFIGURE_ARGS+=	--disable-curl-client
.endif

.if !defined(OPT_LIBWWW) && !defined(OPT_CURL)
PLIST_SUB+=	CLIENT="@comment "
.else
PLIST_SUB+=	CLIENT=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
