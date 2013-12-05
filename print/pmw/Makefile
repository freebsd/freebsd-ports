# Created by: Brian Candler <B.Candler@pobox.com>
# $FreeBSD$

PORTNAME=	pmw
PORTVERSION=	4.27
CATEGORIES=	print audio
MASTER_SITES=	http://www.quercite.com/

MAINTAINER=	5u623l20@gmail.com
COMMENT=	High quality music typesetting program

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
MAKE_ARGS=	FULLECHO=""
ALL_TARGET=	build

SUB_FILES=	pkg-message

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} ChangeLog spec.pdf ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
