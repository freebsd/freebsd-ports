# ex:ts=8
# Ports collection makefile for:  bounce
# Date created:			  Mon Dec 23, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	bounce
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	http://www.iagora.com/~espel/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	obrien
DISTNAME=	bounce
EXTRACT_SUFX=	.c

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bounce tcp connections to another machine/port

NO_WRKSUBDIR=	yes

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${DISTNAME} ${DISTNAME}.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} ${PREFIX}/sbin

.include <bsd.port.mk>
