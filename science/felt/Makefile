# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	felt
PORTVERSION=	3.07
DISTVERSIONSUFFIX=	.src
CATEGORIES=	science
MASTER_SITES=	SF/${PORTNAME}/FElt/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	System for Finite Element Analysis

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS EXAMPLES

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

DEPRECATED=	Unmaintained since 2001
EXPIRATION_DATE=	2014-04-12
USES=		motif
USE_BZIP2=	yes
USE_GL=		glu glw
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix="${PREFIX}" \
		--x-defaults="${LOCALBASE}/lib/X11/app-defaults" \
		--x-includes="${LOCALBASE}/include" \
		--x-libraries="${LOCALBASE}/lib"

MAN1=		burlap.1 corduroy.1 felt.1 patchwork.1 velvet.1 yardstick.1
MAN3=		Drawing.3
MAN4=		corduroy.4 felt.4

DOCSDIR=	${PREFIX}/share/doc/FElt
EXAMPLESDIR=	${PREFIX}/share/examples/FElt

NO_STAGE=	yes
post-patch:
	@${FIND} ${WRKSRC} -name "*.[ch]" | ${XARGS} ${REINPLACE_CMD} -e \
		's|["<]malloc\.h[">]|<stdlib.h>|g'
	@${REINPLACE_CMD} -e \
		'/which CC/s|^|#| ; \
		 /CCOPTS=-O3/s|^.*|CCOPTS=$${CFLAGS}| ; \
		 s|lib/felt|share/felt|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|-lpthread|$$(MOTIFLIB)|' ${WRKSRC}/src/Velvet/Makefile

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/README ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.ans ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.flt ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
