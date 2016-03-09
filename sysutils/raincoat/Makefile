# Created by: Ed Schouten <ed@fxq.nl>
# $FreeBSD$

PORTNAME=	raincoat
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/xbox-linux/Other/Raincoat

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BIOS flash utility for the Microsoft Xbox

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/docs/COPYING

ONLY_FOR_ARCHS=	i386 # Xbox is i386

USES=		tar:tbz2

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/raincoat\.conf|${PREFIX}&|g' \
		${WRKSRC}/docs/README ${WRKSRC}/src/${PORTNAME}.c

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/src/${PORTNAME}.c ${WRKSRC}/src/BootFlash.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/etc/${PORTNAME}.conf ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
