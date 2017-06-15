# Created by: Gabor Kovesdan <gabor@FreeBSD.org>
# $FreeBSD$

PORTNAME=	grep
PORTVERSION=	2.27
CATEGORIES=	textproc
MASTER_SITES=	GNU
PKGNAMEPREFIX=	gnu

MAINTAINER=	johans@FreeBSD.org
COMMENT=	GNU grep

LICENSE=	GPLv3+

CONFLICTS=	bsd-grep-[0-9]*

USES=		charsetfix cpe tar:xz
GNU_CONFIGURE=	yes

INFO=		grep
CPE_VENDOR=	gnu

OPTIONS_DEFINE=		ICONV NLS PCRE
OPTIONS_DEFAULT=	ICONV PCRE
OPTIONS_SUB=		yes

ICONV_CONFIGURE_USES=	iconv
ICONV_CONFIGURE_ON=	--with-libiconv-prefix=${LOCALBASE}
ICONV_CONFIGURE_OFF=	--without-libiconv-prefix

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
NLS_CONFIGURE_ON=	--with-libintl-prefix=${LOCALBASE}
NLS_CONFIGURE_OFF=	--without-libintl-prefix

PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_CONFIGURE_ENABLE=	perl-regexp
PCRE_CPPFLAGS=		-I${LOCALBASE}/include
PCRE_LDFLAGS=		-L${LOCALBASE}/lib
PCRE_CONFIGURE_OFF=	--disable-perl-regexp

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} 's:@grep@:${LOCALBASE}/bin/&:' ${WRKSRC}/src/egrep.sh
.if empty(PORT_OPTIONS:MNLS)
	@${REINPLACE_CMD} '/install-exec-local:/s/install-exec-localcharset//' \
		${WRKSRC}/lib/Makefile.in
.endif
	@${REINPLACE_CMD} 's|mkinstalldirs = .*|mkinstalldirs = ${MKDIR}|g' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
