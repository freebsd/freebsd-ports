# Created by: Matt Peterson <matt@peterson.org>
# $FreeBSD$

PORTNAME=	sortu
PORTVERSION=	2.1.2
CATEGORIES=	sysutils
MASTER_SITES=	http://256.com/sources/sortu/ \
		http://matt.peterson.org/FreeBSD/ports/
EXTRACT_SUFX=	.tgz

MAINTAINER=	matt@peterson.org
COMMENT=	Tool that combines sort and uniq functionality

LICENSE=	ISCL

PORTDOCS=	*
PLIST_FILES=	bin/sortu

ALL_TARGET=	sortu

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sortu ${PREFIX}/bin

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
