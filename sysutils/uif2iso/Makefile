# Created by: Martin Tournoij <carpetsmoker@xs4all.nl>
# $FreeBSD$

PORTNAME=	uif2iso
PORTVERSION=	0.1.7c
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://aluigi.altervista.org/mytoolz/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert MagicISO UIF files to ISO9660

LICENSE=	GPLv2

USES=		zip

WRKSRC=		${WRKDIR}/src

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} 's|exit(1)|exit(0)|' \
		${WRKSRC}/uif2iso.c
	@${REINPLACE_CMD} 's|/usr/local|${STAGEDIR}${PREFIX}|; \
		s|$$(DESTDIR)||' \
		${WRKSRC}/Makefile

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in README uif2iso.txt
	${INSTALL_DATA} ${WRKDIR}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
