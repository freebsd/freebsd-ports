# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	trinokiller
PORTVERSION=	1.0
CATEGORIES=	security
# mastersite disappeared in August 2003
MASTER_SITES=	# http://www.afro-productions.com/
DISTNAME=	trinokiller
EXTRACT_SUFX=	.c

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Remotely kill trino nodes

NO_WRKSUBDIR=	yes
PLIST_FILES=	sbin/trinokiller

NO_STAGE=	yes
do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${DISTNAME} ${DISTNAME}.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} ${PREFIX}/sbin

.include <bsd.port.mk>
