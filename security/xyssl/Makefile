# Created by: mdh <mdh@solitox.net>
# $FreeBSD$

PORTNAME=	xyssl
PORTVERSION=	0.9
DISTVERSIONSUFFIX=	-bsd
PORTREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	http://www.evolane.com/download/mirror/etcl/ \
		http://polarssl.org/code/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight SSL and TLS toolkit for C developers

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/BSD.txt

PORTDOCS=	ChangeLog
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}


NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
.for i in library/Makefile programs/Makefile
	@${REINPLACE_CMD} -e \
		'/^CFLAGS/s|[[:space:]]=| +=| ; \
		 s|^OFLAGS|#OFLAGS| ; \
		 s|^.SILENT:|#.SILENT:|' ${WRKSRC}/${i}
.endfor

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/ChangeLog ${DOCSDIR}
.endif

.include <bsd.port.mk>
