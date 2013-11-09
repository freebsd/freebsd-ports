# Created by: KIMURA Takamichi <takamiti@tsden.org>
# $FreeBSD$

PORTNAME=	extipl
PORTVERSION=	5.04
CATEGORIES=	sysutils
MASTER_SITES=	SFJP/${PORTNAME}/2166

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Partition-selectable boot loader for IBM-PC/AT compatibles

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

ONLY_FOR_ARCHS=	i386 amd64

WRKSRC=		${WRKDIR}/${DISTNAME}/src
OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	cd ${WRKSRC}; \
	${SED} -e 's|!!DOCDIR!!|${DOCSDIR}|g' \
		${PORTNAME}.8.in > ${PORTNAME}.8; \
	${REINPLACE_CMD} -e 's/^(CC)\t=/$$1?=/;' \
		-e 's/(DIR)[\t]*[?]=/$$1=/;' Makefile

do-install:
	${INSTALL_PROGRAM} -m 700 ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MAN8PREFIX}/man/man8
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/English
	${INSTALL_DATA} ${WRKSRC}/../doc/English/*.txt ${STAGEDIR}${DOCSDIR}/English
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/Japanese
	${INSTALL_DATA} ${WRKSRC}/../doc/Japanese/*.txt ${STAGEDIR}${DOCSDIR}/Japanese
.endif

.include <bsd.port.mk>
