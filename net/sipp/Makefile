# New ports collection makefile for:    sipp
# Date created:         15 Jun 2004
# Whom:                 jesper@jdn.dk
#
# $FreeBSD$
#

PORTNAME=	sipp
PORTVERSION=	1.1.r4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	sipp
DISTNAME=	${PORTNAME}-1.1rc4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SIP testing tool

WRKSRC=		${WRKDIR}/${PORTNAME}.cumulus.2005-12-21

PLIST_FILES=	bin/sipp
MAN1=		sipp.1

MAKE_ENV+=	CPP="${CXX}" CPPFLAGS="${CXXFLAGS}" CCLINK="${CXX}"

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		"Does not compile - patch needed by someone who can test it"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/sipp.1 ${PREFIX}/man/man1

.include <bsd.port.post.mk>
