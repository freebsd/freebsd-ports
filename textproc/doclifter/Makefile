# Created by: ijliao
# $FreeBSD$

PORTNAME=	doclifter
PORTVERSION=	2.18
CATEGORIES=	textproc
MASTER_SITES=	http://www.catb.org/~esr/doclifter/

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Translates documents written in troff macros to DocBook

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

USES=		python:2.7 shebangfix
SHEBANG_FILES=	doclifter manlifter
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/doclifter \
		bin/manlifter \
		man/man1/doclifter.1.gz \
		man/man1/manlifter.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/doclifter ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/manlifter ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doclifter.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/manlifter.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
