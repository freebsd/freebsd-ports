# New ports collection makefile for:	prips
# Date created:		29 October 1999
# Whom:			Jeremy Shaffner <jeremy@external.org>
#
# $FreeBSD$
#

PORTNAME=	prips
PORTVERSION=	0.9.4
CATEGORIES=	sysutils
MASTER_SITES=	http://ipsc.sourceforge.net/dist/prips/
DISTNAME=	${PKGNAME}-src

MAINTAINER=	jeremy@external.org
COMMENT=	Prints IP subnet ranges by list or CIDR

WRKSRC=		${WRKDIR}/prips

.include <bsd.port.pre.mk>

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/prips ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.else
	@${SED} 's#share/doc/prips/README##' ${TMPPLIST} > ${WRKDIR}/PLIST.tmp
	@${SED} 's#@dirrm share/doc/prips##' ${WRKDIR}/PLIST.tmp > ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
