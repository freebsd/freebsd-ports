# Created by: snowy
# $FreeBSD$

PORTNAME=	e
PORTVERSION=	0.02718
CATEGORIES=	math
MASTER_SITES=	http://www.softnet.tuc.gr/~apdim/projects/e/

MAINTAINER=	snowy@netphile.de
COMMENT=	Tiny expression evaluator

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2020-05-05

MAKEFILE=	makefile
ALL_TARGET=	e

OPTIONS_DEFINE=	DOCS

post-patch:
	@${RM} ${WRKSRC}/${PORTNAME}
	@${REINPLACE_CMD} -e 's|gcc|${CC}|g ; \
		s|-O2|${CFLAGS}|g' ${WRKSRC}/makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in EXAMPLES GRAMMAR README
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
