PORTNAME=	bibview
PORTVERSION=	2.2
PORTREVISION=	3
CATEGORIES=	print databases
MASTER_SITES=	TEX/biblio/bibtex/utils/bibview-2.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical interface for manipulating BibTeX bibliography databases

USES=		imake xorg
USE_XORG=	ice sm x11 xaw xext xmu xt
WRKSRC=		${WRKDIR}/bibview-${PORTVERSION}

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.mk>
