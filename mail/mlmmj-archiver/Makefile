PORTNAME=	mlmmj-archiver
DISTVERSION=	0.7.1
CATEGORIES=	mail www
MASTER_SITES=	https://codeberg.org/bapt/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Simple mailing archiver designed for mlmmj
WWW=		https://codeberg.org/bapt/mlmmj-archiver

LICENSE=	MIT

LIB_DEPENDS=	libucl.so:textproc/libucl

USES=		sqlite:3 uidfix pkgconfig iconv

WRKSRC=		${WRKDIR}/${PORTNAME}

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir=${PREFIX}/share/man

.include <bsd.port.mk>
