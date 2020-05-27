# Created by: Lasse L. Johnsen (lasse@freebsdcluster.org)
# $FreeBSD$

PORTNAME=	nnap
PORTVERSION=	1.1
CATEGORIES=	news
MASTER_SITES=	http://www.freebsdcluster.org/~lasse/software/
DISTNAME=	nnap-1_1
EXTRACT_SUFX=	.c

MAINTAINER=	lasse@freebsdcluster.org
COMMENT=	Lightweight NNTP authentication proxy

NO_WRKSUBDIR=	yes
PLIST_FILES=	sbin/nnap

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${PORTNAME} ${DISTNAME}.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
