# New ports collection makefile for:  pathchar
# Version required:    a0 (a.out systems), a1 (ELF systems)
# Date created:        7 November 1998
# Whom:                Josh Gilliam <josh@quick.net>
#
# $Id: Makefile,v 1.2 1998/11/16 06:36:06 asami Exp $
#

DISTNAME=	pathchar-a1-freebsd-3.0
PKGNAME=	pathchar-a1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ee.lbl.gov/pathchar/

MAINTAINER=	josh@quick.net

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
