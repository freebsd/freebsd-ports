# ex:ts=8
# Ports collection makefile for:	mirmon
# Date created:			Jun 15, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mirmon
PORTVERSION=	1.36
CATEGORIES=	misc
MASTER_SITES=	http://www.cs.uu.nl/people/henkp/mirmon/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Monitor the status of mirrors

USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes
USE_PERL5_RUN=	yes

PLIST_FILES=	bin/mirmon

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,/etc,${LOCALBASE}/etc," \
		-e "s,/sw/bin/perl,/usr/bin/env perl," \
		-e "s,/sw,${LOCALBASE}," \
		${WRKSRC}/mirmon ${WRKSRC}/mirmon.html

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mirmon ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/countries.list ${WRKSRC}/icons ${DATADIR}
	@${FIND} ${DATADIR} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} ${WRKSRC}/mirmon.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
