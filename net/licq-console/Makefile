# New ports collection makefile for:    console-licq
# Date created:                         18 October 2000
# Whom:                                 Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	console
PORTVERSION=	${CONSOLE_LICQ_VER}
PORTREVISION=	2
CATEGORIES=	net

LIB_DEPENDS=	cdk.4:${PORTSDIR}/devel/cdk

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Ncurses-based console plugin for Licq

USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}" \
		LIBS="${PTHREAD_LIBS}"
LICQ_PORT?=	net/licq
CPPFLAGS+=	${PTHREAD_CFLAGS}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	lib/licq/licq_console.so

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		gp-relative relocation against dynamic symbol
.endif

.include "${PORTSDIR}/${LICQ_PORT}/Makefile.inc"
.include <bsd.port.post.mk>
