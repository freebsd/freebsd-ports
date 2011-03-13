# New ports collection makefile for:   pash
# Date created:        30 December 2000
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	pash
PORTVERSION=	2.2
CATEGORIES=	shells
MASTER_SITES=	http://www.chez-pierre.com/pash/Archives/
DISTNAME=	pash.sources

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A full-screen shell (commander GUI) for *nix.

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

NO_WRKSUBDIR=	yes

MAKEFILE=	makefile

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800000
IGNORE=		Core dumps on execution
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pash ${PREFIX}/bin/pash

post-install:
	@${ECHO} "updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/osh /etc/shells.bak; \
	 ${ECHO_CMD} ${PREFIX}/bin/pash) > /etc/shells
	@${RM} /etc/shells.bak

.include <bsd.port.post.mk>
