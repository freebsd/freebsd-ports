# Created by: ijliao
# $FreeBSD$

PORTNAME=	libdvdcss
PORTVERSION=	1.3.99
CATEGORIES=	multimedia
MASTER_SITES=	http://download.videolan.org/pub/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	Portable abstraction library for DVD decryption

RESTRICTED=	CSS code may violate the DMCA

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gmake libtool pathfix tar:bzip2
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOXYGEN DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOXYGEN}
BUILD_DEPENDS+=	doxygen:devel/doxygen
PORTDOCS=	*
.endif

post-install:
.if ${PORT_OPTIONS:MDOXYGEN}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/doc/html/* ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
