# New ports collection makefile for:	links
# Date created:		21 January 2000
# Whom:			Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

PORTNAME=	links
PORTVERSION=	2.1.p11
PORTEPOCH=	1
CATEGORIES?=	www
MASTER_SITES=	http://atrey.karlin.mff.cuni.cz/~clock/twibright/links/download/
DISTNAME=	${PORTNAME}-2.1pre11

MAINTAINER?=	demon@FreeBSD.org
COMMENT=	Lynx-like text WWW browser

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-javascript --with-ssl --without-svgalib
CONFIGURE_ENV+=	CPPFLAGS='-I${LOCALBASE}/include'
LDFLAGS+=	-L${LOCALBASE}/lib

USE_OPENSSL=	yes
USE_BZIP2=	yes
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_X11)
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff
USE_XLIB=	yes
CONFIGURE_ARGS+=	--enable-graphics --with-x
.endif

MAN1=		links.1
PLIST_FILES=	bin/links

pre-everything::
		@${ECHO_MSG} "Define WITHOUT_X11 to disable graphics support."

post-patch:
	@${REINPLACE_CMD} -e "s!/etc/!${PREFIX}/etc/!" ${WRKSRC}/default.c

.include <bsd.port.post.mk>
