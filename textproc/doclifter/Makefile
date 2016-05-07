# Created by: ijliao
# $FreeBSD$

PORTNAME=	doclifter
PORTVERSION=	2.17
CATEGORIES=	textproc
MASTER_SITES=	http://www.catb.org/~esr/doclifter/

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Translates documents written in troff macros to DocBook

RUN_DEPENDS+=	python2:lang/python2

USES=		python:2 shebangfix
SHEBANG_FILES=	manlifter
NO_BUILD=	yes
NO_ARCH=	yes

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
