# Created by: Nikola Lecic <nikola.lecic@anthesphoria.net>
# $FreeBSD$

PORTNAME=	teckit
PORTVERSION=	2.5.1
CATEGORIES=	textproc
MASTER_SITES=	http://scripts.sil.org/svn-view/teckit/TAGS/ \
		http://anthesphoria.net/FreeBSD/ports/distfiles/
DISTNAME=	TECkit_${PORTVERSION:S|.|_|g}

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	Toolkit for converting data between 8-bit legacy encodings and Unicode

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DOCS=		AUTHORS README NEWS docs/*.pdf license/LICENSING.txt

post-patch:
	${CHMOD} ${BINMODE} ${WRKSRC}/configure ${WRKSRC}/install-sh

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
