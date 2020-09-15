# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	parkverbot
PORTVERSION=	1.3
CATEGORIES=	sysutils
MASTER_SITES=	https://inai.de/files/parkverbot/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Hard disk head parking inhibitor

LICENSE=	GPLv2+

LIB_DEPENDS=	libHX.so:lang/libhx

USES=		pkgconfig tar:xz
GNU_CONFIGURE=	yes

PLIST_FILES=	man/man8/parkverbot.8.gz sbin/parkverbot

post-install:
	${RM} -r ${STAGEDIR}/lib/systemd

.include <bsd.port.mk>
