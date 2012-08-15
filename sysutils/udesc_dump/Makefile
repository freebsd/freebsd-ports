# New ports collection makefile for:	udesc_dump
# Date created:				2002/12/14
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	udesc_dump
PORTVERSION=	1.3.9
CATEGORIES=	sysutils
MASTER_SITES=	http://home.jp.freebsd.org/~gehenna/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shows USB descriptors

MAN8=		udesc_dump.8
MANCOMPRESSED=	yes
PLIST_FILES=	bin/udesc_dump

MAKE_ENV+=	MANDIR=${PREFIX}/man/man

do-patch:
	@${REINPLACE_CMD} 's/-Werror//' ${WRKSRC}/Makefile

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800064
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
