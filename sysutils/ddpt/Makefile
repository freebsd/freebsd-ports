# Created by: Xin Li <delphij@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ddpt
PORTVERSION=	0.94
CATEGORIES=	sysutils
MASTER_SITES=	http://sg.danny.cz/sg/p/
EXTRACT_SUFX=	.tgz

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	dd tool that specializes in files that are block devices

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/ddpt
PLIST_FILES+=	bin/ddptctl
PLIST_FILES+=	man/man8/ddpt.8.gz
PLIST_FILES+=	man/man8/ddptctl.8.gz

.include <bsd.port.mk>
