# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtkextra
PORTVERSION=	2.1.2
PORTREVISION=	4
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME:S/gtk/gtk+/}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Useful widget set complementary to GTK+ 2.0

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake libtool pathfix pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USE_CSTD=	gnu89
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

DOCSDIR=	${PREFIX}/share/doc/gtkextra2

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|docs||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/gtkextra/gtkcharsel.c

post-install-DOCS-on:
.for d in reference tutorial
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/${d}
	@(cd ${WRKSRC}/docs/${d} && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
