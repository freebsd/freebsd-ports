# Created by: Ed Schouten <ed@fxq.nl>
# $FreeBSD$

PORTNAME=	raincoat
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/xbox-linux/Other/Raincoat
EXTRACT_SUFX=	.tbz2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BIOS flash utility for the Microsoft Xbox

# Xbox is i386
ONLY_FOR_ARCHS=		i386
USES=		tar:bzip2
PORTDOCS=	README
OPTIONS_DEFINE=	DOCS

post-patch:
.for f in docs/README src/${PORTNAME}.c
	@${REINPLACE_CMD} -e 's|/etc/raincoat\.conf|${PREFIX}&|g' \
		${WRKSRC}/${f}
.endfor

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/src/${PORTNAME}.c ${WRKSRC}/src/BootFlash.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/etc/${PORTNAME}.conf ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
