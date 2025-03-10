PORTNAME=	dictfmt
PORTVERSION=	1.13.3
CATEGORIES=	textproc
MASTER_SITES=	SF/dict/dictd/dictd-${PORTVERSION}
DISTNAME=	dictd-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Format a DICT protocol dictionary database
WWW=		https://www.dict.org/ \
		https://sourceforge.net/projects/dict/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmaa.so:devel/libmaa

USES=		gmake libtool:build localbase

ALL_TARGET=	dictfmt
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install.dictfmt

.include <bsd.port.mk>
