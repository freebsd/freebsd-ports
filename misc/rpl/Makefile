# ex:ts=8
# Ports collection makefile for:  rpl
# Date created:                          Thu Jul 25, 2002
# Whom:                                  Michael L. Hostbaek (mich@freebsdcluster.org)
#
# $FreeBSD$
#

PORTNAME=	rpl
PORTVERSION=	1.4.0
CATEGORIES=	misc
MASTER_SITES=	http://downloads.laffeycomputer.com/current_builds/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Rpl is a Unix text replacement utility

GNU_CONFIGURE=	yes

MAN1=		rpl.1
PLIST_FILES=	bin/rpl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/rpl ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/rpl.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
