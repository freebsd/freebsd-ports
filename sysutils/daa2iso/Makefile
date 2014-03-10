# Created by: Martin Tournoij <carpetsmoker@xs4all.nl>
# $FreeBSD$

PORTNAME=	daa2iso
PORTVERSION=	0.1.7e
CATEGORIES=	sysutils
MASTER_SITES=	http://aluigi.altervista.org/mytoolz/
DISTNAME=	${PORTNAME}

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Convert PowerISO DAA files to ISO9660

USES=		zip

WRKSRC=		${WRKDIR}/src

PLIST_FILES=	bin/daa2iso
PORTDOCS=	COPYING daa2iso.txt

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} 's|exit(1)|exit(0)|' ${WRKSRC}/daa2iso.c
	@${REINPLACE_CMD} 's|/usr/local|${PREFIX}|' ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKDIR}/${docs} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
