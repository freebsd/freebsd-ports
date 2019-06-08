# $FreeBSD$

PORTNAME=	epson-inkjet-printer-escpr
PORTVERSION=	1.6.41
DISTVERSIONSUFFIX=	-1lsb3.2
CATEGORIES=	print
MASTER_SITES=	https://download3.ebz.epson.net/dsc/f/03/00/09/33/79/927867e2774c98c0fdedb15fc7712f363fe16f41/

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	Epson Inkjet Printer Driver (ESC/P-R) for Linux

LICENSE=	GPLv2+

LIB_DEPENDS=	libcupsimage.so:print/cups

USES=		autoreconf dos2unix gmake libtool
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-lsb
INSTALL_TARGET=	install-strip
SUB_FILES=	pkg-message
PORTDOCS=	AUTHORS COPYING NEWS README README.ja

OPTIONS_DEFINE=	DOCS

PORTSCOUT=	ignore	# MASTER_SITES is changed in each version

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
