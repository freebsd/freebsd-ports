# New ports collection makefile for:	portlint
# Version required:     (self contained)
# Date created:		13 Jun 1997
# Whom:			Jun-ichiro itojun Hagino <itojun@itojun.org>
#
# $FreeBSD$
#
# This port is self contained in the src directory.
#

PORTNAME=	portlint
PORTVERSION=	2.2.1
CATEGORIES=	devel
DISTFILES=	# none

MAINTAINER=	mharo@FreeBSD.org

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_PERL5=	yes

SRC=		${.CURDIR}/src

MAN1=		portlint.1

# didn't use post/pre-fetch because of some weird error where the message
# shows up twice
pre-configure:
	@${ECHO_MSG} "Warning: portlint does not yet support the PORTNAME/PORTVERSION Makefile format"
	@sleep 2

do-fetch:
	@${DO_NADA}

do-install:
	${INSTALL_SCRIPT} ${SRC}/portlint.pl ${PREFIX}/bin/portlint
	${INSTALL_MAN} ${SRC}/portlint.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
