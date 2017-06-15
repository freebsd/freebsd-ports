# Created by: Pawel Pekala <pawel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ports-tools
PORTVERSION=	1.1
CATEGORIES=	ports-mgmt

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Collection of ports tree related scripts

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	ppekala

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/mkpatch bin/pcheck bin/pclean bin/pcommit bin/pfind \
		bin/plist-sort bin/plist-update bin/plog bin/reinplace-check \
		sbin/pkg-deleaf sbin/tbuilder sbin/upgrade-base \
		sbin/upgrade-ports ${DOCSDIR}/README.md

.include <bsd.port.mk>
