PORTNAME=	rnv
PORTVERSION=	1.7.11
PORTREVISION=	1
CATEGORIES=	textproc devel
MASTER_SITES=	SF/${PORTNAME}/Sources/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Relax NG Compact Syntax validator

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-expat="${LOCALBASE}"

CONFLICTS_INSTALL=	arx-libertatis # bin/arx

PLIST_FILES=	bin/arx bin/rnv bin/rvp bin/xsdck man/man1/rnv.1.gz

.include <bsd.port.mk>
