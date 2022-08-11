PORTNAME=	xmlgen
PORTVERSION=	1.4
CATEGORIES=	textproc tcl
MASTER_SITES=	SF/tclxml/${PORTNAME}/v${PORTVERSION}

MAINTAINER=	dereckson@gmail.com
COMMENT=	Write XML documents using Tcl

USES=		tcl
NO_BUILD=	yes

.include <bsd.port.pre.mk>

do-install:
	cd ${WRKSRC} && ${TCLSH} bras-sa PKGDIR=${STAGEDIR}${PREFIX}/lib/${PORTNAME} \
	    DOCDIR=${STAGEDIR}${PREFIX}/share/doc/${PORTNAME} \
	    CGIDIR=${STAGEDIR}${PREFIX}/www/${PORTNAME} install

.include <bsd.port.post.mk>
