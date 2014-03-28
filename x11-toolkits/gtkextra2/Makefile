# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtkextra
PORTVERSION=	2.1.2
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME:S/gtk/gtk+/}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A useful widget set complementary to GTK+ 2.0

USES=		pathfix pkgconfig gmake
USE_GNOME=	gtk20
USE_AUTOTOOLS=	libtool
USE_CSTD=	gnu89
USE_LDCONFIG=	yes

LATEST_LINK=	gtkextra2
DOCSDIR=	${PREFIX}/share/doc/gtkextra2

PORTDOCS=	*

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|docs||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/gtkextra/gtkcharsel.c

post-install:
.if ${PORT_OPTIONS:MDOCS}
.for d in reference tutorial
	@${MKDIR} ${DOCSDIR}/${d}
	@(cd ${WRKSRC}/docs/${d} && ${COPYTREE_SHARE} . ${DOCSDIR})
.endfor
.endif

.include <bsd.port.mk>
