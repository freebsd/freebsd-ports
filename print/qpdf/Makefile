# Created by: Dmitry Kazarov <d.y.kazarov@mail.ru>
# $FreeBSD$

PORTNAME=	qpdf
PORTVERSION=	7.1.1
CATEGORIES=	print
MASTER_SITES=	SF

MAINTAINER=	d.y.kazarov@mail.ru
COMMENT=	Command-line tools for transforming and inspecting PDF documents

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/Artistic-2.0

USES=		gmake jpeg libtool localbase
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
