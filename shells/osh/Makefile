# New ports collection makefile for:   osh
# Date created:        29 December 2000
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	osh
PORTVERSION=	020214
CATEGORIES=	shells
MASTER_SITES=	http://omnibus.ruf.uni-freiburg.de/~gritter/archive/

MAINTAINER=	greid@ukug.uk.freebsd.org

MAKEFILE=	makefile

MAN1=		goto.1 if.1 osh.1

post-install:
	@${ECHO} "updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/osh /etc/shells.bak; \
	 ${ECHO_CMD} ${PREFIX}/bin/osh) > /etc/shells
	@${RM} /etc/shells.bak

.include <bsd.port.mk>
