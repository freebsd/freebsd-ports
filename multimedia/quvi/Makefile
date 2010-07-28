# New ports collection makefile for:	quvi
# Date created:		2 February 2010
# Whom:			Toni Gundogdu <legatvs@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	quvi
PORTVERSION=	0.1.4
CATEGORIES=	multimedia devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Query video library for Youtube like websites

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		pcre.0:${PORTSDIR}/devel/pcre

USE_LDCONFIG=	yes
SHLIB_VER=	1

MAKE_ENV=	SHLIB_VER="${SHLIB_VER}"
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"

MAN1=		quvi.1

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig
USE_ICONV=	yes

CONFIGURE_ENV+=	CPPFLAGS='${CPPFLAGS} -I${WRKSRC}/include \
		-I${LOCALBASE}/include'

OPTIONS=	SMUT "Enable adult website support" off

.include <bsd.port.pre.mk>

.if defined(WITH_SMUT)
CONFIGURE_ARGS+=--enable-smut
.endif

post-patch:
	@${REINPLACE_CMD} -E -e \
		's|\$$\(libdir\)/pkgconfig|\$$\(prefix\)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
