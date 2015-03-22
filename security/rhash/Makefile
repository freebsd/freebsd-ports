# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rhash
PORTVERSION=	1.3.3
CATEGORIES=	security
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Utility and library for computing and checking of file hashes

LICENSE=	MIT

USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	ChangeLog README

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/,${PREFIX}&,' ${WRKSRC}/parse_cmdline.c

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
