# $FreeBSD$

PORTNAME=	ctpl
PORTVERSION=	0.3.4
CATEGORIES=	textproc devel
MASTER_SITES=	http://download.tuxfamily.org/ctpl/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C Template (Parser) Library

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USE_GNOME=	glib20
USES=		pathfix pkgconfig libtool
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext-runtime

.include <bsd.port.mk>
