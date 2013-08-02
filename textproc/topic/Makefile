# $FreeBSD$

PORTNAME=	topic
PORTVERSION=	1.02
CATEGORIES=	textproc
MASTER_SITES=	# http://topcat.hypermart.net/code/

MAINTAINER=	mike@topcat.hypermart.net
COMMENT=	Topic markup parser

PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1

pre-build:
	@${RM} ${WRKSRC}/topic.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
