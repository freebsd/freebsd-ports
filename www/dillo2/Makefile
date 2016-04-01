# Created by: bf <bf2006a@yahoo.com>
# $FreeBSD$

PORTNAME=	dillo
PORTVERSION=	3.0.5
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.dillo.org/download/ LOCAL/bf/dillo/ \
		TEX_CTAN/language/hyph-utf8/tex/generic/hyph-utf8/patterns/txt/:hyphen
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Fast, small graphical Web browser built upon fltk

LICENSE=	GPLv3

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk
RUN_DEPENDS=	wget:ftp/wget

USES=		gmake iconv pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/libexec
CONFLICTS=	dillo-i18n-[0-9]* \
		dillo-0*

OPTIONS_DEFINE=		COOKIES HYPHENATION IPV6 SSL THREADS DOCS
OPTIONS_DEFAULT=	COOKIES HYPHENATION IPV6 SSL THREADS

COOKIES_DESC=		Cookie support
HYPHENATION_DESC=	Hyphenation file(s) for HYPHENATION_LANGS
SSL_DESC=		Experimental HTTPS support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCOOKIES}
CONFIGURE_ARGS+=	--enable-cookies
.else
CONFIGURE_ARGS+=	--disable-cookies
.endif

.ifdef(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-gprof --enable-rtfl
.else
CONFIGURE_ARGS+=	--disable-gprof --disable-rtfl
.endif

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
.endif

.if ${PORT_OPTIONS:MHYPHENATION}
ALL_HYPHENATION_LANGS=	af as bg bn ca cop cs cy da de-1901 de-1996 \
de-ch-1901 el-monoton el-polyton en-gb en-us eo es et eu fi fr fur ga \
gl grc gu hi hr hsb hu hy ia id is it ka kmr kn la la-x-classic lt lv ml mn-cyrl mr \
mul-ethi nb nl nn or pa pl pms pt rm ro ru sa sh-cyrl sh-latn sk sl \
sr-cyrl sv ta te th tk tr uk zh-latn-pinyin
.if defined(MAINTAINER_MODE) || make(makesum)
HYPHENATION_LANGS?=	${ALL_HYPHENATION_LANGS}
.else
HYPHENATION_LANGS?=	\
	${ALL_HYPHENATION_LANGS:N*-1901:N*-classic:N*-latn:N*-gb:N*-monoton}
.endif
.for _l in ${HYPHENATION_LANGS}
.if !${ALL_HYPHENATION_LANGS:M${_l}}
IGNORE=	remove the invalid hyphenation language "${_l}" from HYPHENATION_LANGS
.else
DISTFILES+=	hyph-${_l}.pat.txt:hyphen
PLIST_FILES+=	libexec/dillo/hyphenation/${_l:C/-.*\$//}.pat
.endif
.endfor
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${PORT_OPTIONS:MSSL}
CONFIGURE_ARGS+=	--enable-ssl
USE_OPENSSL=	yes
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=	--enable-threaded-dns
.else
CONFIGURE_ARGS+=	--disable-threaded-dns
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
.if ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e "\|install-data-am:|s|install-dist_docDATA||" \
		${WRKSRC}/doc/Makefile.in
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}
.endif
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/dillo/hyphenation
.if ${PORT_OPTIONS:MHYPHENATION}
.for _l in ${HYPHENATION_LANGS}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/hyph-${_l}.pat.txt \
	${STAGEDIR}${PREFIX}/libexec/dillo/hyphenation/${_l:C/-.*\$//}.pat
.endfor
.endif

.include <bsd.port.mk>
