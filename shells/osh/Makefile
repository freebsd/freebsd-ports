# New ports collection makefile for:   osh
# Date created:        29 December 2000
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	osh
PORTVERSION=	040812
PORTREVISION=	1
CATEGORIES=	shells
MASTER_SITES=	http://jneitzel.sdf1.org/osh/src/
PATCHFILES=	osh-040812-osh_c.patch
PATCH_SITES=	${MASTER_SITES}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An implementation of the UNIX 6th Edition shell

MAN1=		goto.1 if.1 osh.1

post-install:
	@${ECHO_MSG} "updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/osh /etc/shells.bak; \
	 ${ECHO_CMD} ${PREFIX}/bin/osh) > /etc/shells
	@${RM} /etc/shells.bak

.include <bsd.port.mk>
