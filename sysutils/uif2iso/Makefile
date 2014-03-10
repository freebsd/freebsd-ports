# Created by: Martin Tournoij <carpetsmoker@xs4all.nl>
# $FreeBSD$

PORTNAME=	uif2iso
PORTVERSION=	0.1.7c
CATEGORIES=	sysutils
MASTER_SITES=	http://aluigi.altervista.org/mytoolz/
DISTNAME=	${PORTNAME}

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Convert MagicISO UIF files to ISO9660

USES=		zip
WRKSRC=		${WRKDIR}/src

PLIST_FILES=	bin/uif2iso
PORTDOCS=	README uif2iso.txt

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} 's|exit(1)|exit(0)|' ${WRKSRC}/uif2iso.c
	@${REINPLACE_CMD} 's|/usr/local|${PREFIX}|' ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKDIR}/${docs} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
