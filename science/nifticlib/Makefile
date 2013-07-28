# Created by: Jason Bacon <bacon@smithers.neuro.mcw.edu>
# $FreeBSD$

PORTNAME=	nifticlib
PORTVERSION=	1.1.0
CATEGORIES=	science graphics
MASTER_SITES=	SF/niftilib/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Neuroimaging Informatics Technology Initiative data format

USES=		gmake

MAN1=		nifticlib.1

post-patch:
	@${REINPLACE_CMD} -e 's/include depend.mk/-&/' \
		${WRKSRC}/fsliolib/Makefile ${WRKSRC}/nifticdf/Makefile \
		${WRKSRC}/niftilib/Makefile ${WRKSRC}/znzlib/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/* ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/include
	${INSTALL_MAN} ${FILESDIR}/nifticlib.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
