# New ports collection makefile for:   slrn
# Date created:        28 March 1997
# Whom:                Carey Jones <mcj@acquiesce.org>
#
# $FreeBSD$
#

PORTNAME=	slrn
PORTVERSION=	0.9.9p1
PORTREVISION=	2
CATEGORIES=	news ipv6
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION} \
		ftp://angel.sovam.com/pub/tools/net/news/ \
		ftp://ftp.fu-berlin.de/pub/unix/news/slrn/ \
		ftp://ftp.ntua.gr/pub/lang/slang/slrn/ \
		ftp://ftp.plig.org/pub/slrn/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	SLang-based newsreader

LIB_DEPENDS=	slang.2:${PORTSDIR}/devel/libslang2

USE_GMAKE=	yes
USE_ICONV=	yes

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-ipv6 --disable-inews --with-slrnpull \
			--with-libiconv-prefix=${LOCALBASE}

.if !defined(WITHOUT_SSL)
USE_OPENSSL=	YES
CONFIGURE_ARGS+=	--with-ssl
.endif

.if defined(WITH_DEVIEW)
LIB_DEPENDS+=	uu.3:${PORTSDIR}/converters/uulib
CONFIGURE_ARGS+=	--with-uulib
.endif

.if defined(NOPORTDOCS)
# Use dummy target rather than rewriting makefile
CONFIGURE_ARGS+=	--with-docdir=${WRKSRC}/dummy
.endif

ALL_TARGET=	all

MAN1=		slrn.1 slrnpull.1

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/lib/sendmail,/usr/sbin/sendmail,' \
		${WRKSRC}/src/slrnfeat.hin
	@${REINPLACE_CMD} -e 's,malloc.h,stdlib.h,' \
		${WRKSRC}/src/jdmacros.h

.include <bsd.port.mk>
