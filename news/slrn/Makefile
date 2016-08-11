# Created by: Carey Jones <mcj@acquiesce.org>
# $FreeBSD$

PORTNAME=	slrn
PORTVERSION=	1.0.2
CATEGORIES=	news ipv6
MASTER_SITES=	http://www.jedsoft.org/releases/slrn/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	SLang-based newsreader

LIB_DEPENDS=	libslang.so:devel/libslang2

CONFLICTS_INSTALL=	ja-slrn-[0-9]*

USES=		gmake iconv tar:bz2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-inews --with-slrnpull \
		--with-non-gnu-iconv ${ICONV_CONFIGURE_ARG}

ALL_TARGET=	all

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	NLS SSL DEVIEW DOCS
OPTIONS_DEFAULT=SSL
OPTIONS_SUB=	yes
NLS_USES=		gettext
NLS_CONFIGURE_OFF=	--disable-nls
SSL_USE=		OPENSSL
SSL_CONFIGURE_WITH=	ssl
DEVIEW_DESC?=		UUdecode view support
DEVIEW_LIB_DEPENDS=	libuu.so:converters/uulib
DEVIEW_CONFIGURE_WITH=	uulib
DOCS_CONFIGURE_OFF=	--with-docdir=${WRKSRC}/dummy

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/lib/sendmail,/usr/sbin/sendmail,' \
		${WRKSRC}/src/slrnfeat.hin
	@${REINPLACE_CMD} -e 's,malloc.h,stdlib.h,' \
		${WRKSRC}/src/jdmacros.h

.include <bsd.port.mk>
