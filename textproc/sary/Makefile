# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	sary
PORTVERSION=	1.2.0
PORTREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	http://sary.sourceforge.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Suffix array library and tools, which provide fast full-text search

GNU_CONFIGURE=	yes
USES=		gnome libtool pathfix pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|docs||g' ${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${FIND} . ! -name "*Makefile*" | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsary.so

.include <bsd.port.mk>
