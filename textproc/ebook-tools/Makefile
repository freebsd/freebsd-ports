# Created by: Martin Wilke <miwi@FreeBSD.org>

PORTNAME=	ebook-tools
PORTVERSION=	0.2.2
PORTREVISION=	5
CATEGORIES=	textproc kde
MASTER_SITES=	SF

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Accesses and converts various ebook file formats

LICENSE=	MIT

LIB_DEPENDS=	libzip.so:archivers/libzip

USES=		cmake gnome
USE_LDCONFIG=	yes
USE_GNOME=	libxml2

CONFLICTS_INSTALL=	ncbi-entrez-direct # bin/einfo

.include <bsd.port.mk>
