# $FreeBSD$

PORTNAME=	epson-inkjet-printer-escpr
PORTVERSION=	1.6.38
DISTVERSIONSUFFIX=	-1lsb3.2
CATEGORIES=	print
MASTER_SITES=	https://download3.ebz.epson.net/dsc/f/03/00/09/25/30/1b345288d691386af8a0314a9b11ecbc400522ec/

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	Epson Inkjet Printer Driver (ESC/P-R) for Linux

LICENSE=	GPLv2+

LIB_DEPENDS=	libcupsimage.so:print/cups
FETCH_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

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
