# Created by: Andrey Chernov <ache@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lynx
PORTVERSION=	2.8.8.2
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	www ipv6
MASTER_SITES=	http://invisible-mirror.net/archives/lynx/tarballs/ \
		http://bitrote.org/distfiles/
DISTNAME=	${PORTNAME}${PORTVERSION:R}rel.${PORTVERSION:E}

MAINTAINER=	jharris@widomaker.com
COMMENT=	Non-graphical, text-based World-Wide Web client

LICENSE=	GPLv2

CONFLICTS=	lynx-2.8.[8-9]d*

USES=		cpe ncurses shebangfix tar:bzip2
SHEBANG_FILES=	samples/mailto-form.pl
WRKSRC=		${WRKDIR}/${PORTNAME}2-8-8
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-zlib --libdir="${PREFIX}/etc" \
		--enable-nsl-fork --enable-persistent-cookies \
		--enable-nested-tables --enable-gzip-help \
		--with-screen=ncursesw
CPE_VERSION=	${PORTVERSION:R}
CPE_UPDATE=	rel.${PORTVERSION:E}

MAKEFILE=	makefile
L_HELP=		${PREFIX}/share/lynx_help
SUB_FILES=	pkg-message
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DEFAULT_COLORS IPV6 NLS SSL DOCS EXTERNALS
OPTIONS_DEFAULT=	SSL EXTERNALS
DEFAULT_COLORS_DESC=	Colors support
EXTERNALS_DESC=	External application support
OPTIONS_SUB=	yes

NLS_USES=	gettext iconv
NLS_CONFIGURE_ENABLE=	nls
NLS_CONFIGURE_ON=	${ICONV_CONFIGURE_ARG}

IPV6_CONFIGURE_ENABLE=	ipv6

DEFAULT_COLORS_CONFIGURE_ENABLE=	default-colors

DOCS_CONFIGURE_ENABLE=	local-docs
DOCS_INSTALL_TARGET=	install-full
DOCS_MAKE_ARGS=		helpdir=${L_HELP} docdir=${DOCSDIR}

EXTERNALS_CONFIGURE_ENABLE=externs

SSL_CONFIGURE_ON=	--with-ssl=${OPENSSLBASE}
SSL_USES=		ssl

post-install-DOCS-on:
# Fix some stage symlinks
.for doc in COPYHEADER COPYING COPYHEADER.asc COPYING.asc
	(cd ${STAGEDIR}${L_HELP} && ln -sf ../doc/lynx/${doc} .)
.endfor

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MSSL} && ${SSL_DEFAULT:Mopenssl-devel}
BROKEN=		Does not build with openssl-devel
.endif

.include <bsd.port.post.mk>
