# Created by: Carey Jones <mcj@acquiesce.org>
# $FreeBSD$

PORTNAME=	slrn
PORTVERSION=	1.0.1
CATEGORIES=	news ipv6
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME} \
		http://www.jedsoft.org/slrn/download/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	SLang-based newsreader

LIB_DEPENDS=	slang:${PORTSDIR}/devel/libslang2

CONFLICTS_INSTALL=	ja-slrn-[0-9]*

USE_GMAKE=	yes
USE_ICONV=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-ipv6 --disable-inews --with-slrnpull \
			--with-libiconv-prefix=${LOCALBASE}

ALL_TARGET=	all

MAN1=		slrn.1 slrnpull.1

OPTIONS_DEFINE=	SSL DEVIEW
OPTIONS_DEFAULT=SSL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MSSL}
USE_OPENSSL=	YES
CONFIGURE_ARGS+=	--with-ssl
.endif

.if ${PORT_OPTIONS:MDEVIEW}
LIB_DEPENDS+=	uu:${PORTSDIR}/converters/uulib
CONFIGURE_ARGS+=	--with-uulib
.endif

.if ! ${PORT_OPTIONS:MDOCS}
# Use dummy target rather than rewriting makefile
CONFIGURE_ARGS+=	--with-docdir=${WRKSRC}/dummy
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/lib/sendmail,/usr/sbin/sendmail,' \
		${WRKSRC}/src/slrnfeat.hin
	@${REINPLACE_CMD} -e 's,malloc.h,stdlib.h,' \
		${WRKSRC}/src/jdmacros.h

.include <bsd.port.mk>
