# New ports collection makefile for:	ile
# Version required:	2.0
# Date created:		25 Jun 1997
# Whom:			jmz
#
# $FreeBSD$
#

DISTNAME=	lile-2.0
PKGNAME=	ile-2.0
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.inria.fr/system/user/
EXTRACT_SUFX=	.tar.z

MAINTAINER=	jmz@FreeBSD.org

MAN1=		ile.1

do-configure:
	@(cd ${WRKSRC}; ${MV} Makefile Makefile.old; \
	${SED} -e s:/usr/local:${PREFIX}: <Makefile.old > Makefile; \
	${ECHO} all: ile >> Makefile; ${ECHO} CC=cc ${CFLAGS} >> Makefile)

.include <bsd.port.mk>
