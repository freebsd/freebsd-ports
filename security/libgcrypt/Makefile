# New ports collection Makefile for:	libgcrypt
# Date created:				July 17 2002
# Whom:					Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libgcrypt
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	libgcrypt

MAINTAINER=	arved@FreeBSD.org
COMMENT=	"General purpose crypto library based on code used in GnuPG"

LIB_DEPENDS=	gpg-error.1:${PORTSDIR}/security/libgpg-error

USE_REINPLACE=	yes
USE_INC_LIBTOOL_VER=15
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

INFO=	gcrypt

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
CONFIGURE_ARGS+=	--disable-asm
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|" \
		${WRKSRC}/ltmain.sh

pre-configure:
	@${RM} -f ${WRKSRC}/doc/gcrypt.info*

.include <bsd.port.post.mk>
