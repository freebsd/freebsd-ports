# New Ports collection makefile for:  bounce
# Date created:			  Mon Dec 23, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	bounce
PORTVERSION=	1.0
PORTREVISION=	8
CATEGORIES=	net security
MASTER_SITES=	http://www.iagora.com/~espel/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	obrien
DISTNAME=	bounce
EXTRACT_SUFX=	.c

MAINTAINER=	matt@efs.org
COMMENT=	Bounce tcp connections to another machine/port

USE_RC_SUBR=	bounce
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	sbin/bounce

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${DISTNAME} ${DISTNAME}.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} ${PREFIX}/sbin

.include <bsd.port.mk>
