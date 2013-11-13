# Created by: Jean-Sebastien Roy <js@jeannot.org>
# $FreeBSD$

PORTNAME=	xtexsh
PORTVERSION=	1.4.2
PORTREVISION=	6
CATEGORIES=	print
MASTER_SITES=	http://www.mat.univie.ac.at/~gerald/ftp/xtexsh/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tcl/Tk-based simple TeX interface

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}
NO_BUILD=	yes

USE_TEX=	latex
USES+=		tk desktop-file-utils
INSTALLS_ICONS=	yes
PORTDOCS=	*

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/bin/wish|${WISH}|g ; \
		s|"/etc|"${PREFIX}/etc| ; \
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

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/index.html ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
