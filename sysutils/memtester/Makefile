# Created by: Mario S F Ferreira <lioux@linf.unb.br> et al.
# $FreeBSD$

PORTNAME=	memtester
PORTVERSION=	4.5.0
CATEGORIES=	sysutils
MASTER_SITES=	http://pyropus.ca/software/${PORTNAME}/old-versions/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Utility to test for faulty memory subsystem

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

PLIST_FILES=	bin/${PORTNAME} man/man8/${PORTNAME}.8.gz

post-patch:
	@${REINPLACE_CMD} -e 's|cc|${CC}|' \
		${WRKSRC}/conf-*
	@${REINPLACE_CMD} -e 's|_SC_PAGE_SIZE|_SC_PAGESIZE|' \
		${WRKSRC}/${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
