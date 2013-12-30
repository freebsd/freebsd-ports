# Created by: ijliao
# $FreeBSD$

PORTNAME=	mirmon
PORTVERSION=	2.9
CATEGORIES=	misc
MASTER_SITES=	http://www.staff.science.uu.nl/~penni101/mirmon/

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Monitor the status of mirrors

NO_BUILD=	yes
USES=		perl5
USE_PERL5=	run

SUB_FILES=	pkg-message
SUB_LIST=	PREFIX=${PREFIX}

PLIST_FILES=	bin/mirmon bin/probe
MAN1=		mirmon.1

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,/etc,${LOCALBASE}/etc," \
		${WRKSRC}/mirmon ${WRKSRC}/mirmon.html ${WRKSRC}/probe
	@${REINPLACE_CMD} -e "s,/usr/bin/wget,${LOCALBASE}/bin/wget," \
		-e "s,/usr/bin/rsync,${LOCALBASE}/bin/rsync," ${WRKSRC}/probe

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mirmon ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/probe ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -R ${WRKSRC}/countries.list ${WRKSRC}/icons ${STAGEDIR}${DATADIR}
	@${FIND} ${STAGEDIR}${DATADIR} ! -type d | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.if ! ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} ${WRKSRC}/mirmon.html ${STAGEDIR}${DOCSDIR}
.endif

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
