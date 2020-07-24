# Created by: KIMURA Takamichi <takamiti@tsden.org>
# $FreeBSD$

PORTNAME=	extipl
PORTVERSION=	5.04
CATEGORIES=	sysutils
MASTER_SITES=	OSDN/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Partition-selectable boot loader for IBM-PC/AT compatibles

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	nasm:devel/nasm

ONLY_FOR_ARCHS=	i386 amd64

BUILD_WRKSRC=	${WRKSRC}/src

OPTIONS_DEFINE=	DOCS

post-patch:
	@cd ${WRKSRC}/src && ${SED} -e 's|!!DOCDIR!!|${DOCSDIR}|g' \
		${PORTNAME}.8.in > ${PORTNAME}.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/src/${PORTNAME}.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/English
	${INSTALL_DATA} ${WRKSRC}/doc/English/*.txt ${STAGEDIR}${DOCSDIR}/English
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/Japanese
	${INSTALL_DATA} ${WRKSRC}/doc/Japanese/*.txt ${STAGEDIR}${DOCSDIR}/Japanese

.include <bsd.port.mk>
