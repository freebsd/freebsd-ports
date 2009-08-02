# New ports collection makefile for:	glide3
# Date created:				31 Mar 2001
# Whom:					Nick Sayer <nsayer@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	driglide
PORTVERSION=	0.9.1
PORTREVISION=	6
CATEGORIES=	x11-servers
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	anholt/driglide/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libraries to support 3dfx Voodoo3/4/5/Banshee with the DRI

USE_XORG=	xxf86vm xxf86dga
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	automake:14 autoconf:262 libtool:22
AUTOMAKE_ARGS=	-a
USE_GMAKE=	yes
MAKE_ARGS=	PREPROCESSOR=/usr/bin/cpp
# Not yet ported to Alpha.
ONLY_FOR_ARCHS=	i386

# Glide DOES NOT work with CFLAGS greater than -O2
CFLAGS+=	-O

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' \
		${WRKSRC}/configure.in \
		${WRKSRC}/h3/glide3/src/Makefile.am \
		${WRKSRC}/h5/glide3/src/Makefile.am
	@${REINPLACE_CMD} -e \
		's|(float \*)pointers +=|pointers += sizeof(float *) *|' \
		${WRKSRC}/h3/glide3/src/gaa.c \
		${WRKSRC}/h3/glide3/src/gdraw.c \
		${WRKSRC}/h3/glide3/src/distrip.c \
		${WRKSRC}/h5/glide3/src/gaa.c \
		${WRKSRC}/h5/glide3/src/gdraw.c \
		${WRKSRC}/h5/glide3/src/distrip.c

pre-configure:
	@cd ${WRKSRC} && ${ACLOCAL} -I ${LOCALBASE}/share/aclocal
	@${REINPLACE_CMD} -e '/^_LT_AC_SHELL_INIT/d' ${WRKSRC}/aclocal.m4

.include <bsd.port.mk>
