# New ports collection makefile for:  pathchar
# Version required:    a0 (a.out systems), a1 (ELF systems)
# Date created:        7 November 1998
# Whom:                Josh Gilliam <josh@quick.net>
#
# $Id: Makefile,v 1.3 1999/01/05 01:07:23 steve Exp $
#

DISTNAME=	pathchar-a1-freebsd-3.0
PKGNAME=	pathchar-a1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ee.lbl.gov/pathchar/

MAINTAINER=	josh@quick.net

ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>
.if ${PORTOBJFORMAT} == "aout"
DISTNAME=	pathchar-a0-freebsd-2.2
PKGNAME=	pathchar-a0
.endif

NO_BUILD=	yes
NO_WRKSUBDIR=   yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pathchar ${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/README.pathchar \
		${PREFIX}/share/doc/README.pathchar

.include <bsd.port.post.mk>
