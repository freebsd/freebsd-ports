PORTNAME=	ebook-tools
PORTVERSION=	0.2.2
PORTREVISION=	9
CATEGORIES=	textproc kde
MASTER_SITES=	SF

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Accesses and converts various ebook file formats
WWW=		https://sourceforge.net/projects/ebook-tools/

LICENSE=	MIT

LIB_DEPENDS=	libzip.so:archivers/libzip

USES=		cmake gnome
USE_LDCONFIG=	yes
USE_GNOME=	libxml2

CONFLICTS_INSTALL=	ncbi-entrez-direct # bin/einfo

.include <bsd.port.mk>
