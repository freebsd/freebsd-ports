# New ports collection makefile for:  pathchar
# Version required:    a0 (a.out systems), a1 (ELF systems)
# Date created:        7 November 1998
# Whom:                Josh Gilliam <josh@quick.net>
#
# $FreeBSD$
#

DISTNAME=	pathchar-a1-freebsd-3.0
PKGNAME=	pathchar-a1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ee.lbl.gov/pathchar/  \
		http://www.caida.org/Tools/Pathchar/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} pathcharnotes.html

MAINTAINER=	josh@quick.net

ONLY_FOR_ARCHS=	i386
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "aout"
DISTNAME=	pathchar-a0-freebsd-2.2
PKGNAME=	pathchar-a0
.endif

NO_BUILD=	yes
NO_WRKSUBDIR=   yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pathchar ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/pathchar
	${INSTALL_MAN} ${FILESDIR}/README.pathchar \
		${DISTDIR}/pathcharnotes.html \
		${PREFIX}/share/doc/pathchar
.endif

.include <bsd.port.post.mk>
