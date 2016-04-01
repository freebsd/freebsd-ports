# $FreeBSD$

PORTNAME=	zrep
PORTVERSION=	1.0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.bolthole.com/solaris/zrep/ \
		http://www.bsdstore.ru/downloads/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=

MAINTAINER=	olevole@olevole.ru
COMMENT=	ZFS based replication and failover solution

RUN_DEPENDS=	ksh93:shells/ksh93

PLIST_FILES=	bin/zrep

NO_BUILD=	yes

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|#!/bin/ksh -p|#!${PREFIX}/bin/ksh93 -p|' ${WRKSRC}/zrep

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} -p ${DISTDIR}/${PORTNAME} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin

.include <bsd.port.mk>
