# Created by: Oliver Braun <obraun@FreeBSD.org>
# $FreeBSD$

PORTNAME=	multitail
PORTVERSION=	6.4.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.vanheusden.com/multitail/ \
		http://fossies.org/unix/privat/

MAINTAINER=	beat@FreeBSD.org
COMMENT=	Tail multiple files on console with ncurses

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		alias gmake ncurses tar:tgz

PLIST_FILES=	bin/multitail etc/multitail.conf.sample \
		man/man1/multitail.1.gz
PORTDOCS=	readme.txt license.txt

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,$$(DESTDIR)/etc/multitail.conf,${PREFIX}/etc/multitail.conf,' \
		-e 's/CC=gcc/CC?=gcc/' \
		${WRKSRC}/mt.c ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/multitail ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/multitail.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/multitail.conf ${STAGEDIR}${PREFIX}/etc/multitail.conf.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/license.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
