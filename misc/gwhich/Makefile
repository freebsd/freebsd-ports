# New ports collection makefile for:	gwhich
# Date created:		20 September 2000
# Whom:			Jeremy Shaffner <jeremy@external.org>
#
# $FreeBSD$
#

PORTNAME=	gwhich
PORTVERSION=	2.14
CATEGORIES=	misc
MASTER_SITES=	http://www.xs4all.nl/~carlo17/which/
DISTNAME=	which-${PORTVERSION}

MAINTAINER=	jeremy@external.org
COMMENT=	GNU Which - Everything you never wanted in a which

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --program-prefix=g

MAN1=		gwhich.1

post-install:
	@install-info ${PREFIX}/info/which.info ${PREFIX}/info/dir
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/examples/gwhich
	@${INSTALL_DATA} ${WRKSRC}/EXAMPLES ${PREFIX}/share/examples/gwhich/EXAMPLES
.else
	@${SED} 's#share/examples/gwhich/EXAMPLES##' ${TMPPLIST} > ${WRKDIR}/PLIST.tmp
	@${SED} 's#@dirrm share/examples/gwhich##' ${WRKDIR}/PLIST.tmp > ${TMPPLIST}
.endif

.include <bsd.port.mk>
