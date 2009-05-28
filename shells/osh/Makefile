# New ports collection makefile for:   osh
# Date created:        29 December 2000
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	osh
DISTVERSION=	20090527
CATEGORIES=	shells
MASTER_SITES=	http://v6shell.org/src/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	An implementation of the UNIX 6th Edition shell

MAN1=		fd2.1 goto.1 if.1 osh.1 sh6.1 glob6.1

post-install:
	@${ECHO_MSG} "updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/osh /etc/shells.bak; \
	 ${ECHO_CMD} ${PREFIX}/bin/osh) > /etc/shells
	@${RM} /etc/shells.bak

.include <bsd.port.mk>
