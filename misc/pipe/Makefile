# ex:ts=8
# Ports collection makefile for:	pipe
# Date created:			Feb 9, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pipe
PORTVERSION=	0.b.1.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	petri-net
DISTNAME=	${PORTNAME}-beta-1.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Platform Independent Petri-Net Editor

BROKEN=		Size mismatch

USE_ZIP=	yes
WRKSRC=		${WRKDIR}/PIPE
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_JAVA=	yes

PLIST_FILES=	bin/pipe

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-extract:
	@${SED} 's,%%DATADIR%%,${DATADIR},' ${FILESDIR}/pipe > ${WRKSRC}/pipe

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pipe ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/bin/ ${DATADIR}
	@${FIND} ${DATADIR} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}
.endif

.include <bsd.port.mk>
