# New ports collection makefile for:    sipp
# Date created:         15 Jun 2004
# Whom:                 jesper@jdn.dk
#
# $FreeBSD$
#

PORTNAME=	sipp
PORTVERSION=	1.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	sipp
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	jesper@jdn.dk
COMMENT=	SIP testing tool

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	bin/sipp
MAN1=		sipp.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		"Does not compile - patch needed by someone who can test it"
.endif

pre-install:
	@${CP} ${FILESDIR}/${MAN1} ${WRKSRC}/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sipp.1 ${PREFIX}/man/man1/sipp.1

.include <bsd.port.post.mk>
