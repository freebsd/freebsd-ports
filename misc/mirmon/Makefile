# ex:ts=8
# Ports collection makefile for:	mirmon
# Date created:			Jun 15, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mirmon
PORTVERSION=	2.4
CATEGORIES=	misc
MASTER_SITES=	http://people.cs.uu.nl/henkp/mirmon/

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Monitor the status of mirrors

NO_BUILD=	yes
USE_PERL5_RUN=	yes

SUB_FILES=	pkg-message
SUB_LIST=	PREFIX=${PREFIX}

PLIST_FILES=	bin/mirmon bin/probe
MAN1=		mirmon.1

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,/etc,${LOCALBASE}/etc," \
		${WRKSRC}/mirmon ${WRKSRC}/mirmon.html ${WRKSRC}/probe
	@${REINPLACE_CMD} -e "s,/usr/bin/wget,${LOCALBASE}/bin/wget," \
		-e "s,/usr/bin/rsync,${LOCALBASE}/bin/rsync," ${WRKSRC}/probe

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mirmon ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/probe ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/countries.list ${WRKSRC}/icons ${DATADIR}
	@${FIND} ${DATADIR} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	${INSTALL_MAN} ${WRKSRC}/mirmon.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} ${WRKSRC}/mirmon.html ${DOCSDIR}
.endif

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
