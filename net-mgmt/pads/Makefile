# Created by: Andrew Thompson <andy@fud.org.nz>
# $FreeBSD$

PORTNAME=	pads
PORTVERSION=	1.2
PORTREVISION=	6
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/passive/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Passively detect network assets

USES=		shebangfix
SHEBANG_FILES=	src/pads-report.pl
CFLAGS+=	-Wno-return-type
USE_CSTD=	gnu89

LIB_DEPENDS=	libpcre.so:devel/pcre

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
