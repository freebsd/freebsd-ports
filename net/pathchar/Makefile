# ex:ts=8
# Ports collection makefile for:  pathchar
# Date created:			  7 November 1998
# Whom:				  Josh Gilliam <josh@quick.net>
#
# $FreeBSD$
#

PORTNAME=	pathchar
PORTVERSION=	a1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ee.lbl.gov/pathchar/:lbl  \
		http://www.caida.org/tools/utilities/others/pathchar/:caida \
		http://sitka.triumf.ca/net/:sitka  \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	obrien/:local
DISTNAME=	pathchar-a1-freebsd-3.0
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:lbl pathcharnotes.html:caida,local \
		pathchar.8:local pathchar.mantxt:sitka,local

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LBNL Internet path characterization tool

IGNORE=		coredumps immediately, see PR ports/124404
DEPRECATED=	has been broken for 2+ years, no sources available
EXPIRATION_DATE=2010-09-01

ONLY_FOR_ARCHS=	i386
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
MAN8=		pathchar.8

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

pre-patch:
	@${CP} ${DISTDIR}/pathchar.8 ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pathchar ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pathchar.8 ${PREFIX}/man/man8
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/pathchar
	${INSTALL_MAN} ${FILESDIR}/README.pathchar \
		${DISTDIR}/pathcharnotes.html \
		${DISTDIR}/pathchar.mantxt \
		${PREFIX}/share/doc/pathchar
.endif

.include <bsd.port.mk>
