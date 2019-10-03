# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	direvent
PORTVERSION=	5.2
CATEGORIES=	sysutils
MASTER_SITES=	GNU

MAINTAINER=	zeus@gnu.org.ua
COMMENT=	Per-directory file system event monitor

LICENSE=	GPLv3+

USES=		gmake
GNU_CONFIGURE=	yes
TEST_TARGET=	check

INFO=		${PORTNAME}

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime
NLS_CONFIGURE_OFF=	--disable-nls

.include <bsd.port.mk>
