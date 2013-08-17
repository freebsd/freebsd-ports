# Created by: ijliao
# $FreeBSD$
#

PORTNAME=	doclifter
PORTVERSION=	2.12
CATEGORIES=	textproc
MASTER_SITES=	http://www.catb.org/~esr/doclifter/

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Translates documents written in troff macros to DocBook

RUN_DEPENDS+=	python2:${PORTSDIR}/lang/python2

USE_PYTHON=	-2.7
NO_BUILD=	yes

MAN1=		doclifter.1 manlifter.1
PLIST_FILES=	bin/doclifter bin/manlifter

post-patch:
	${REINPLACE_CMD} '1s/python/python2/' ${WRKSRC}/doclifter

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/doclifter ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/manlifter ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doclifter.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/manlifter.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
