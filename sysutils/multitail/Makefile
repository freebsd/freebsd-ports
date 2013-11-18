# Created by: Oliver Braun <obraun@FreeBSD.org>
# $FreeBSD$

PORTNAME=	multitail
PORTVERSION=	5.2.12
CATEGORIES=	sysutils
MASTER_SITES=	http://www.vanheusden.com/multitail/ \
		http://fossies.org/unix/privat/
EXTRACT_SUFX=	.tgz

MAINTAINER=	beat@FreeBSD.org
COMMENT=	Tail multiple files on console with ncurses

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		gmake

PLIST_FILES=	bin/multitail etc/multitail.conf.sample \
		man/man1/multitail.1.gz
PORTDOCS=	readme.txt license.txt

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/multitail.conf,${PREFIX}/etc/multitail.conf,' \
		-e 's/CC=gcc/CC?=gcc/' \
		${WRKSRC}/mt.c ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/multitail ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/multitail.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/multitail.conf ${STAGEDIR}${PREFIX}/etc/multitail.conf.sample
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/license.txt ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
