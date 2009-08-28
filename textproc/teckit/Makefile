# New ports collection makefile for:    teckit
# Date created:		24 August 2009
# Whom:			Nikola Lecic <nikola.lecic@anthesphoria.net>
#
# $FreeBSD$
#

PORTNAME=	teckit
PORTVERSION=	2.5.1
CATEGORIES=	textproc
MASTER_SITES=	http://scripts.sil.org/svn-view/teckit/TAGS/ \
		http://anthesphoria.net/FreeBSD/ports/distfiles/
DISTNAME=	TECkit_${PORTVERSION:S|.|_|g}

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	Toolkit for converting data between 8-bit legacy encodings and Unicode

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

DOCS=		AUTHORS README NEWS docs/*.pdf license/LICENSING.txt

post-patch:
	${CHMOD} ${BINMODE} ${WRKSRC}/configure ${WRKSRC}/install-sh

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
