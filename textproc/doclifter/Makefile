# Created by: ijliao
# $FreeBSD$

PORTNAME=	doclifter
PORTVERSION=	2.13
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.catb.org/~esr/doclifter/

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Translates documents written in troff macros to DocBook

RUN_DEPENDS+=	python2:${PORTSDIR}/lang/python2

USE_PYTHON=	2
NO_BUILD=	yes

PLIST_FILES=	bin/doclifter \
		bin/manlifter \
		man/man1/doclifter.1.gz \
		man/man1/manlifter.1.gz

post-patch:
	${REINPLACE_CMD} '1s/python/python2/' ${WRKSRC}/doclifter

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/doclifter ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/manlifter ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doclifter.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/manlifter.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
