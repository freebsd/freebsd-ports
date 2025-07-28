PORTNAME=	ctpl
DISTVERSION=	0.3.5
CATEGORIES=	textproc devel
MASTER_SITES=	https://git.tuxfamily.org/ctpl/ctpl.git/snapshot/

MAINTAINER=	alven@FreeBSD.org
COMMENT=	C Template (Parser) Library
WWW=		https://ctpl.tuxfamily.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gtk-doc>0:textproc/gtk-doc

USES=		autoreconf gettext-tools gmake gnome libtool pathfix pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip
TEST_TARGET=	check # PASS: 4/4

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

DOCS_CONFIGURE_ENABLE=	gtk-doc
NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
