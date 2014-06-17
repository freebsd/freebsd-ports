# Created by: Dmitry Kazarov <d.y.kazarov@mail.ru>
# $FreeBSD$

PORTNAME=	qpdf
PORTVERSION=	5.1.1
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	SF

MAINTAINER=	d.y.kazarov@mail.ru
COMMENT=	Command-line tools for transforming and inspecting PDF files

LICENSE=	ART20

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gmake libtool

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|' \
		-e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/make/libtool.mk

.include <bsd.port.mk>
