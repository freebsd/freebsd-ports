# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	osinfo-db
PORTVERSION=	20161026
CATEGORIES=	misc
MASTER_SITES=	https://fedorahosted.org/releases/l/i/libosinfo/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Osinfo database files

BUILD_DEPENDS=	osinfo-db-tools>=1.1.0:sysutils/osinfo-db-tools

USES=		tar:xz
NO_BUILD=	yes

do-extract: # nada

do-install:
	osinfo-db-import --root ${STAGEDIR} --system ${DISTDIR}/${DISTFILES}

.include <bsd.port.mk>
