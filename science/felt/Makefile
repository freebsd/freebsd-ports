# New ports collection makefile for:	FElt
# Date created:		19 October 1996
# Whom:			Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	felt
PORTVERSION=	3.06
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	SF/${PORTNAME}/FElt/${PORTVERSION}devel
EXTRACT_SUFX=	-devel.src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A system for Finite Element Analysis

LIB_DEPENDS=	GLw.1:${PORTSDIR}/graphics/libGLw

WRKSRC=		${WRKDIR}/FElt-${PORTVERSION}

USE_MOTIF=	yes
USE_GL=		glu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--x-defaults=${LOCALBASE}/lib/X11/app-defaults
CFLAGS+=	-D__GLX_MOTIF

MAN1=		burlap.1 corduroy.1 felt.1 patchwork.1 velvet.1 yardstick.1
MAN3=		Drawing.3
MAN4=		corduroy.4 felt.4

DOCSDIR=	${PREFIX}/share/doc/FElt
EXAMPLESDIR=	${PREFIX}/share/examples/FElt

post-extract:
	@cd ${WRKSRC}/include && ${RM} -rf X11

post-patch:
	@${FIND} ${WRKSRC} -name "*.[ch]" | ${XARGS} ${REINPLACE_CMD} -e \
		's|["<]malloc\.h[">]|<stdlib.h>|g'

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/README ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.ans ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.flt ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
