# New ports collection makefile for:	meld
# Date created:				2003-04-13
# Whom:					Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$
#

PORTNAME=	meld
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	textproc devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	meld
EXTRACT_SUFX=	.tgz

MAINTAINER=	rui@ruilopes.com
COMMENT=	GNOME 2 visual diff and merge tool

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gnome/__init__.py:${PORTSDIR}/x11-toolkits/py-gnome2

USE_PYTHON=	yes
USE_X_PREFIX=	yes
NO_BUILD=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes

MAKEFILE=	GNUmakefile

post-patch:
	@${REINPLACE_CMD} -E 's,(prefix := )(.*),\1${PREFIX},g ; \
		s,(libdir := )(.*),\1${PREFIX}/share,g ; \
		s,( glade2/pixmaps/\*\.){xpm\,png},\1xpm\1png,g' ${WRKSRC}/GNUmakefile
	@${REINPLACE_CMD} -E 's,(.+)(install )-D (-m 644 \$$\^ \$$@),\1mkdir -m 755 -p $$(shell dirname $$@) \&\& \2\3,g' ${WRKSRC}/po/GNUmakefile
	@${REINPLACE_CMD} -e 's,^Path=.*$$,Icon=${DATADIR}/glade2/pixmaps/icon.png,' ${WRKSRC}/meld.desktop

post-install:
	${INSTALL_DATA} ${WRKSRC}/meld.desktop ${PREFIX}/share/gnome/applications
	${INSTALL_DATA} ${WRKSRC}/manual/stylesheet.css ${DOCSDIR}
	@cd ${DATADIR} && \
		${PYTHON_CMD} -c "import compileall; compileall.compile_dir('.', 0)"

.include <bsd.port.mk>
