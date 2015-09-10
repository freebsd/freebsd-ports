# Created by: Chris Hutchinson <portmaster@bsdforge.com>
# $FreeBSD$

PORTNAME=	smi
PORTVERSION=	1.4
CATEGORIES=	textproc www
MASTER_SITES=	http://bsdforge.com/projects/source/textproc/${PORTNAME}/

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Simple Markdown Interpreter / filter for simplified markup dialect

LICENSE=	MIT BSD2CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

PORTDOCS=	README.md

PLIST_FILES=	bin/smi man/man1/smi.1.gz

USES=		tar:xz

post-patch:
	${REINPLACE_CMD} -e 's|^CC = .*|CC = ${CC}|' \
			 -e 's|^PREFIX = .*|PREFlX = ${PREFIX}|' \
			 -e 's|^MANPREFIX = .*|MANPREFIX = ${MANPREFIX}|' \
			 ${WRKSRC}/config.mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/smi ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/smi.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
