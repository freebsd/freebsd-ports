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

MAINTAINER=	nork@FreeBSD.org
COMMENT=	udesc_dump, showes USB descriptors

MAN8=		udesc_dump.8
MANCOMPRESSED=	yes
PLIST_FILES=	bin/udesc_dump

MAKE_ENV+=	MANDIR=${PREFIX}/man/man

USE_REINPLACE=	yes

do-patch:
	@${REINPLACE_CMD} 's/-Werror//' ${WRKSRC}/Makefile

.include <bsd.port.mk>
