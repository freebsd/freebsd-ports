# ex:ts=8
# Ports collection makefile for:  telserv
# Version required:     	  1.0
# Date created:			  Mon Feb 03, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $Id: Makefile,v 1.2 1997/01/25 18:08:40 obrien Exp $
#

DISTNAME=	telserv
PKGNAME=	telserv-1.0
CATEGORIES=	net security
MASTER_SITES=	http://www.eleves.ens.fr:8080/home/espel/  \
		http://www.freebsd.org/~obrien/Distfiles/
DISTFILES=	${DISTNAME}.c

MAINTAINER=     obrien@FreeBSD.org

NO_WRKSUBDIR=	yes

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${DISTNAME} ${DISTNAME}.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} ${PREFIX}/libexec

.include <bsd.port.mk>
