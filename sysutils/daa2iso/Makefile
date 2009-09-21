# New ports collection makefile for:	sysutils/daa2iso
# Date created:				27 Jan 2008
# Whom:					Martin Tournoij <carpetsmoker@xs4all.nl>
#
# $FreeBSD$
#

PORTNAME=	daa2iso
PORTVERSION=	0.1.7e
CATEGORIES=	sysutils
MASTER_SITES=	http://aluigi.altervista.org/mytoolz/
DISTNAME=	${PORTNAME}

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	Convert PowerISO DAA files to ISO9660

USE_ZIP=	yes

WRKSRC=		${WRKDIR}/src

PLIST_FILES=	bin/daa2iso
PORTDOCS=	COPYING daa2iso.txt

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
