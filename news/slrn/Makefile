# New ports collection makefile for:   slrn
# Date created:        28 March 1997
# Whom:                Carey Jones <mcj@acquiesce.org>
#
# $FreeBSD$
#

PORTNAME=	slrn
PORTVERSION=	0.9.8.0
PORTREVISION=	2
CATEGORIES=	news ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.rge.com/pub/usenet/readers/unix/slrn/ \
		ftp://angel.sovam.com/pub/tools/net/news/ \
		ftp://ftp.fu-berlin.de/pub/unix/news/slrn/ \
		ftp://ftp.ntua.gr/pub/lang/slang/slrn/ \
		ftp://ftp.plig.org/pub/slrn/
		
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	petef@FreeBSD.org
COMMENT=	SLang-based newsreader

LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang \
		iconv.3:${PORTSDIR}/converters/libiconv

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-ipv6 --disable-inews --with-slrnpull \
		--with-libiconv-prefix=${LOCALBASE}
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib"

.if !defined(WITHOUT_SSL)
USE_OPENSSL=	YES
CONFIGURE_ARGS+=	--with-ssl
.endif

ALL_TARGET=	all

MAN1=		slrn.1 slrnpull.1

.if defined(NOPORTDOCS)
MAKE_ENV+=      NOPORTDOCS=yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/lib/sendmail,/usr/sbin/sendmail,' \
		${WRKSRC}/src/slrnfeat.h
	@${REINPLACE_CMD} -e 's,malloc.h,stdlib.h,' \
		${WRKSRC}/src/jdmacros.h

.include <bsd.port.mk>
