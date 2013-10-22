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

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}
NO_BUILD=	yes

USE_TEX=	latex
USE_TK_WRAPPER=	yes
INSTALLS_ICONS=	yes
MAN1=		xtexsh.1
MANCOMPRESSED=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/bin|${LOCALBASE}/bin|g ; \
		s|"/etc|"${PREFIX}/etc| ; \
		s|exec bash|exec sh|' ${WRKSRC}/xtexsh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xtexsh ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xtexsh.1.gz ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/xtexshrc ${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/xtexsh.desktop ${PREFIX}/share/applications
	@${MKDIR} ${PREFIX}/share/icons/locolor/16x16/apps
	${INSTALL_DATA} ${WRKSRC}/xtexsh-mini.png \
		${PREFIX}/share/icons/locolor/16x16/apps/xtexsh.png
	@${MKDIR} ${PREFIX}/share/icons/locolor/32x32/apps
	${INSTALL_DATA} ${WRKSRC}/xtexsh.png \
		${PREFIX}/share/icons/locolor/32x32/apps/xtexsh.png
	${INSTALL_DATA} ${WRKSRC}/xtexsh.png ${PREFIX}/share/pixmaps

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/index.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
