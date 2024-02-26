PORTNAME=	xml-format
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML beautifier
WWW=		https://acadix.biz/xml-format.php

MAKE_ENV+=	DATADIR=${DATADIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} Config ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
