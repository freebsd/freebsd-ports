# Created by: Brian Candler <B.Candler@pobox.com>
# $FreeBSD$

PORTNAME=	pmw
PORTVERSION=	4.28
CATEGORIES=	print audio
MASTER_SITES=	http://www.quercite.com/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	High quality music typesetting program

BROKEN=		unfetchable

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
MAKE_ARGS=	FULLECHO=""
ALL_TARGET=	build

SUB_FILES=	pkg-message

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} ChangeLog spec.pdf ${STAGEDIR}${DOCSDIR})
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pmw

.include <bsd.port.mk>
