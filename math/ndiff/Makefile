# New ports collection makefile for:   ndiff
# Date created:        31 January 2004
# Whom:                Stefan A. Deutscher (sad@mailaps.org)
#
# $FreeBSD$
#

PORTNAME=	ndiff
PORTVERSION=	2.00
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.math.utah.edu/pub/misc/
PKGNAMEPREFIX=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compare putatively similar files, ignoring small numeric differences

.if !defined(WITHOUT_GMP)
LIB_DEPENDS=	gmp:${PORTSDIR}/math/libgmp-freebsd
.endif

GNU_CONFIGURE=	yes
ALL_TARGET=	all check

MAN1=		ndiff.1
.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-build:
	@${ECHO_MSG} "If there were no errors in the above checks then type"
	@${ECHO_MSG}
	@${ECHO_MSG} "	${MAKE} install"
	@${ECHO_MSG}
	@${ECHO_MSG} "to install ${PORTNAME}-${PORTVERSION}"

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.pdf  ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.ps   ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
