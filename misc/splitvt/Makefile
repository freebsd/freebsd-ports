# ex:ts=8
# Ports collection makefile for:  Splitvt
# Date created:			  Fri Oct 4, 1996
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	splitvt
PORTVERSION=	1.6.3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/console

MAINTAINER=	obrien@FreeBSD.org

FORBIDDEN=	"Doesn't change permissions on pty, leaving it mode 666. Making it setuid isn't a solution because there's a buffer overflow."

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure
ALL_TARGET=
MAN1=			splitvt.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/splitvt ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/splitvt.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
