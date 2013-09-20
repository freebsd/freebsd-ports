# Created by: Alexander Kabaev <ak03@gte.com>
# $FreeBSD$

PORTNAME=	bwidget
PORTVERSION=	1.9.2
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/tcllib/BWidget/${PORTVERSION}
DISTNAME=	BWidget-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A high-level widget set for Tcl/Tk

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_TK_RUN=	84+

NO_BUILD=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

NO_STAGE=	yes
do-install:
	@$(MKDIR) ${PREFIX}/lib/bwidget
	${INSTALL_DATA} ${WRKSRC}/*.tcl ${PREFIX}/lib/bwidget
	${TAR} -C ${WRKSRC} -cf - images lang | \
		${TAR} -v -C ${PREFIX}/lib/bwidget --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/bwidget
.if !defined(NOPORTDOCS)
	@$(MKDIR) ${DOCSDIR}/BWman
	${INSTALL_DATA} ${WRKSRC}/BWman/*.html ${DOCSDIR}/BWman
. for FILE in CHANGES.txt ChangeLog README.txt
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}/${FILE}
. endfor
.endif

.include <bsd.port.mk>
