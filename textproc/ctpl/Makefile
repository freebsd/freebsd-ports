PORTNAME=	ctpl
PORTVERSION=	0.3.4
PORTREVISION=	1
CATEGORIES=	textproc devel
MASTER_SITES=	http://download.tuxfamily.org/ctpl/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C Template (Parser) Library
WWW=		https://ctpl.tuxfamily.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_GNOME=	glib20
USES=		gnome libtool pathfix pkgconfig
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext-runtime

.include <bsd.port.mk>
