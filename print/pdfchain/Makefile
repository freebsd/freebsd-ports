# $FreeBSD$

PORTNAME=	pdfchain
PORTVERSION=	0.4.4.2
CATEGORIES=	print
MASTER_SITES=	https://sourceforge.net/projects/pdfchain/files/pdfchain-${PORTVERSION}/

MAINTAINER=	chapelet@gmail.com
COMMENT=	Graphical user interface for the PDF Toolkit (PDFtk)

LICENSE=	GPLv3

USES=		desktop-file-utils
USES+=		gettext-runtime
USES+=		gnome
USES+=		pkgconfig

GNU_CONFIGURE=	yes

USE_GNOME=	atk
USE_GNOME+=	atkmm
USE_GNOME+=	cairo
USE_GNOME+=	cairomm
USE_GNOME+=	gdkpixbuf2
USE_GNOME+=	glib20
USE_GNOME+=	glibmm
USE_GNOME+=	gtk30
USE_GNOME+=	gtkmm30
USE_GNOME+=	libsigc++20
USE_GNOME+=	pango
USE_GNOME+=	pangomm

INSTALLS_ICONS=	yes

.include <bsd.port.mk>
