PORTNAME=	pdfchain
PORTVERSION=	0.4.4.2
CATEGORIES=	print
MASTER_SITES=	SF/pdfchain/pdfchain-${PORTVERSION}

MAINTAINER=	chapelet@gmail.com
COMMENT=	Graphical user interface for the PDF Toolkit (PDFtk)

LICENSE=	GPLv3

USES=		compiler:c++11-lang desktop-file-utils gettext-runtime gnome \
		pkgconfig
USE_GNOME=	atk atkmm cairo cairomm gdkpixbuf2 glib20 glibmm gtk30 gtkmm30 \
		libsigc++20 pango pangomm
INSTALLS_ICONS=	yes

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
