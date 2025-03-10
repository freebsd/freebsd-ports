PORTNAME=	indexinfo
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	print ports-mgmt
MASTER_SITES=	https://codeberg.org/bapt/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Utility to regenerate the GNU info page index
WWW=		https://codeberg.org/bapt/indexinfo

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USE_CSTD=	gnu99
INSTALL_TARGET=	install-strip
PLIST_FILES=	bin/indexinfo
WRKSRC=		${WRKDIR}/${PORTNAME}

.if exists(/usr/include/sys/capsicum.h)
CFLAGS+=	-DHAVE_CAPSICUM
.endif

.include <bsd.port.mk>
