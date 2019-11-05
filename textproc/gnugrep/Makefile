# Created by: Gabor Kovesdan <gabor@FreeBSD.org>
# $FreeBSD$

PORTNAME=	grep
PORTVERSION=	3.3
CATEGORIES=	textproc
MASTER_SITES=	GNU
PKGNAMEPREFIX=	gnu

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	GNU version of popular pattern matching utility

LICENSE=	GPLv3+

CONFLICTS=	bsd-grep-[0-9]*

USES=		charsetfix cpe tar:xz
GNU_CONFIGURE=	yes
TEST_TARGET=	check

INFO=		grep
CPE_VENDOR=	gnu

OPTIONS_DEFINE=		ICONV LIBSIGSEGV NLS PCRE
OPTIONS_DEFAULT=	ICONV PCRE
LIBSIGSEGV_DESC=	Use alternative page fault handler (GNU libsigsegv)
OPTIONS_SUB=		yes

ICONV_CONFIGURE_USES=	iconv
ICONV_CONFIGURE_ON=	--with-libiconv-prefix=${LOCALBASE}
ICONV_CONFIGURE_OFF=	--without-libiconv-prefix

LIBSIGSEGV_LIB_DEPENDS=	libsigsegv.so:devel/libsigsegv
LIBSIGSEGV_CONFIGURE_ON=	--with-libsigsegv-prefix=${LOCALBASE}
LIBSIGSEGV_CONFIGURE_OFF=	--without-libsigsegv-prefix

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
NLS_CONFIGURE_ON=	--with-libintl-prefix=${LOCALBASE}
NLS_CONFIGURE_OFF=	--without-libintl-prefix

PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_USES=		pkgconfig
PCRE_CONFIGURE_ENABLE=	perl-regexp

post-patch:
	@${REINPLACE_CMD} 's:@grep@:${PREFIX}/bin/&:' ${WRKSRC}/src/egrep.sh
	@${REINPLACE_CMD} 's|mkinstalldirs = .*|mkinstalldirs = ${MKDIR}|g' \
		${WRKSRC}/po/Makefile.in.in

post-patch-NLS-off:
	@${REINPLACE_CMD} '/install-exec-local:/s/install-exec-localcharset//' \
		${WRKSRC}/lib/Makefile.in

.include <bsd.port.mk>
