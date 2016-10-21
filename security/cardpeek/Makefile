# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cardpeek
PORTVERSION=	0.8.4
CATEGORIES=	security
MASTER_SITES=	http://downloads.pannetrat.com/install/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Tool for reading the contents of ISO 7816 smart cards

LICENSE=	GPLv3

LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite \
		libcurl.so:ftp/curl
RUN_DEPENDS=	pcscd:devel/pcsc-lite

USES=		execinfo iconv localbase lua pkgconfig
USE_GNOME=	gtk30
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

PLIST_FILES=	bin/cardpeek man/man1/cardpeek.1.gz \
		share/appdata/cardpeek.appdata.xml \
		share/applications/cardpeek.desktop \
		share/icons/hicolor/48x48/apps/cardpeek-logo.png
PORTDOCS=	AUTHORS README cardpeek_ref.en.pdf

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,^doc_DATA =,& AUTHORS README,' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
