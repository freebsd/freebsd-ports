# Created by: Jean-Sebastien Roy <js@jeannot.org>
# $FreeBSD$

PORTNAME=	xtexsh
DISTVERSION=	1.4-2
PORTREVISION=	6
CATEGORIES=	print
MASTER_SITES=	http://www.mat.univie.ac.at/~gerald/ftp/xtexsh/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tcl/Tk-based simple TeX interface

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		desktop-file-utils gnome shebangfix tk
USE_TEX=	latex
SHEBANG_FILES=	xtexsh
INSTALLS_ICONS=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}
NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|"/etc|"${PREFIX}/etc|; \
		s|exec bash|exec sh|' ${WRKSRC}/xtexsh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xtexsh ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xtexsh.1.gz ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/xtexshrc ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/xtexsh.desktop ${STAGEDIR}${PREFIX}/share/applications
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/locolor/16x16/apps
	${INSTALL_DATA} ${WRKSRC}/xtexsh-mini.png \
		${STAGEDIR}${PREFIX}/share/icons/locolor/16x16/apps/xtexsh.png
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/locolor/32x32/apps
	${INSTALL_DATA} ${WRKSRC}/xtexsh.png \
		${STAGEDIR}${PREFIX}/share/icons/locolor/32x32/apps/xtexsh.png
	${INSTALL_DATA} ${WRKSRC}/xtexsh.png ${STAGEDIR}${PREFIX}/share/pixmaps

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/index.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
