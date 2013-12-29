# Created by: Carey Jones <mcj@acquiesce.org>
# $FreeBSD$

PORTNAME=	slrn
PORTVERSION=	1.0.1
CATEGORIES=	news ipv6
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME} \
		http://www.jedsoft.org/slrn/download/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	SLang-based newsreader

LIB_DEPENDS=	libslang.so:${PORTSDIR}/devel/libslang2

CONFLICTS_INSTALL=	ja-slrn-[0-9]*

USES=		gmake iconv

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-ipv6 --disable-inews --with-slrnpull \
		${ICONV_CONFIGURE_ARG}

ALL_TARGET=	all

OPTIONS_DEFINE=	NLS SSL DEVIEW
OPTIONS_DEFAULT=NLS SSL
OPTIONS_SUB=	yes
NLS_USES=		gettext
NLS_CONFIGURE_OFF=	--disable-nls
SSL_USE=		OPENSSL
SSL_CONFIGURE_WITH=	ssl
DEVIEW_DESC?=		UUdecode view support
DEVIEW_LIB_DEPENDS=	libuu.so:${PORTSDIR}/converters/uulib
DEVIEW_CONFIGURE_WITH=	uulib
DOCS_CONFIGURE_OFF=	--with-docdir=${WRKSRC}/dummy

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/lib/sendmail,/usr/sbin/sendmail,' \
		${WRKSRC}/src/slrnfeat.hin
	@${REINPLACE_CMD} -e 's,malloc.h,stdlib.h,' \
		${WRKSRC}/src/jdmacros.h

.include <bsd.port.mk>
