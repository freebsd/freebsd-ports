# ex:ts=8
# Ports collection makefile for:  telserv
# Date created:			  Mon Feb 03, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	telserv
PORTVERSION=	1.0
CATEGORIES=	net security
MASTER_SITES=	http://www.eleves.ens.fr:8080/home/espel/  \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	obrien
DISTNAME=	telserv
EXTRACT_SUFX=	.c

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A telnet server analogous to the unix talk command

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

NO_WRKSUBDIR=	yes

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${DISTNAME} ${DISTNAME}.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} ${PREFIX}/libexec

.include <bsd.port.mk>
