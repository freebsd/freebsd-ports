# New ports collection makefile for:	ile
# Date created:		25 Jun 1997
# Whom:			jmz
#
# $FreeBSD$
#

PORTNAME=	ile
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.inria.fr/system/user/
DISTNAME=	lile-2.0
EXTRACT_SUFX=	.tar.z

MAINTAINER=	jmz@FreeBSD.org

MAN1=		ile.1

do-configure:
	@(cd ${WRKSRC}; ${MV} Makefile Makefile.old; \
	${SED} -e s:/usr/local:${PREFIX}: <Makefile.old > Makefile; \
	${ECHO_CMD} all: ile >> Makefile; ${ECHO_CMD} CC=cc ${CFLAGS} >> Makefile)

.include <bsd.port.mk>
