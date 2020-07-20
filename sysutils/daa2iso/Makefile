# Created by: Martin Tournoij <carpetsmoker@xs4all.nl>
# $FreeBSD$

PORTNAME=	daa2iso
PORTVERSION=	0.1.7e
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://aluigi.altervista.org/mytoolz/ \
		http://aluigi.zenhax.com/mytoolz/
DISTNAME=	${PORTNAME}

MAINTAINER=	marcel@herrbischoff.com
COMMENT=	Convert PowerISO DAA files to ISO9660

LICENSE=	GPLv2

USES=		zip

WRKSRC=		${WRKDIR}/src

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} 's|exit(1)|exit(0)|' \
		${WRKSRC}/daa2iso.c
	@${REINPLACE_CMD} 's|/usr/local|${STAGEDIR}${PREFIX}|' \
		${WRKSRC}/Makefile

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in COPYING daa2iso.txt
	${INSTALL_DATA} ${WRKDIR}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
