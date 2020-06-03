# Created by: bf <bf2006a@yahoo.com>
# $FreeBSD$

PORTNAME=	dillo
PORTVERSION=	3.0.5
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.dillo.org/download/ \
		LOCAL/bf/dillo/ \
		TEX_CTAN/language/hyph-utf8/tex/generic/hyph-utf8/patterns/txt/:hyphen
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast, small graphical Web browser built upon fltk

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk \
		libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	wget:ftp/wget

USES=		gmake iconv pkgconfig tar:bzip2 xorg
USE_XORG=	x11 xcursor xext xfixes xft xinerama xrender

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-efence \
		--disable-insure \
		--libdir=${PREFIX}/libexec
LDFLAGS+=	-lthr

PORTDOCS=	*

OPTIONS_DEFINE=		COOKIES DEBUG DOCS HYPHENATION IPV6 JPEG PNG SSL \
			THREADS
OPTIONS_DEFAULT=	COOKIES HYPHENATION IPV6 JPEG PNG SSL THREADS

COOKIES_DESC=		Cookie support
HYPHENATION_DESC=	Hyphenation file(s) for HYPHENATION_LANGS
SSL_DESC=		Experimental HTTPS support

DEBUG_CONFIGURE_ENABLE=	gprof rtfl

COOKIES_CONFIGURE_ENABLE=	cookies

IPV6_CONFIGURE_ENABLE=	ipv6

JPEG_CONFIGURE_ENABLE=	jpeg
JPEG_USES=		jpeg

PNG_CONFIGURE_ENABLE=	png
PNG_LIB_DEPENDS=	libpng.so:graphics/png

SSL_USES=		ssl
SSL_CONFIGURE_ENABLE=	ssl
SSL_EXTRA_PATCHES=	${PATCHDIR}/extra-patches-openssl

THREADS_CONFIGURE_ENABLE=	threaded-dns

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MHYPHENATION}
ALL_HYPHENATION_LANGS=	af as bg bn ca cop cs cy da de-1901 de-1996 de-ch-1901 \
			el-monoton el-polyton en-gb en-us eo es et eu fi fr fur \
			ga gl grc gu hi hr hsb hu hy ia id is it ka kmr kn la \
			la-x-classic lt lv ml mn-cyrl mr mul-ethi nb nl nn or \
			pa pl pms pt rm ro ru sa sh-cyrl sh-latn sk sl sr-cyrl \
			sv ta te th tk tr uk zh-latn-pinyin
.if defined(MAINTAINER_MODE) || make(makesum)
HYPHENATION_LANGS?=	${ALL_HYPHENATION_LANGS}
.else
HYPHENATION_LANGS?=	${ALL_HYPHENATION_LANGS:N*-1901:N*-classic:N*-latn:N*-gb:N*-monoton}
.endif
.for _l in ${HYPHENATION_LANGS}
.if !${ALL_HYPHENATION_LANGS:M${_l}}
IGNORE=		remove the invalid hyphenation language "${_l}" from HYPHENATION_LANGS
.else
DISTFILES+=	hyph-${_l}.pat.txt:hyphen
PLIST_FILES+=	libexec/dillo/hyphenation/${_l:C/-.*\$//}.pat
.endif
.endfor
.endif

post-patch:
	@${MV} ${WRKSRC}/dillorc ${WRKSRC}/dillorc.sample
	@${MV} ${WRKSRC}/dpid/dpidrc.in ${WRKSRC}/dpid/dpidrc.sample.in
	@${MV} ${WRKSRC}/src/domainrc ${WRKSRC}/src/domainrc.sample
	@${MV} ${WRKSRC}/src/keysrc ${WRKSRC}/src/keysrc.sample
	@${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|g" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s|dillorc|dillorc.sample|g" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|dpidrc|dpidrc.sample|g" ${WRKSRC}/dpid/Makefile.in
	@${REINPLACE_CMD} -E "s/(domain|keys)rc/&.sample/g" ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e "s|/lib/dillo|/libexec/dillo|" \
		${WRKSRC}/dillo-install-hyphenation \
		${WRKSRC}/doc/dillo.1.in \
		${WRKSRC}/dpid/dpid.c

post-patch-DOCS-on:
	@${REINPLACE_CMD} -e "\|install-data-am:|s|install-dist_docDATA||" \
		${WRKSRC}/doc/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/dillo/hyphenation

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

post-install-HYPHENATION-on:
.for _l in ${HYPHENATION_LANGS}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/hyph-${_l}.pat.txt \
	${STAGEDIR}${PREFIX}/libexec/dillo/hyphenation/${_l:C/-.*\$//}.pat
.endfor

.include <bsd.port.post.mk>
