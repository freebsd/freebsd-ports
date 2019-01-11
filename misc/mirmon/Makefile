# Created by: ijliao
# $FreeBSD$

PORTNAME=	mirmon
PORTVERSION=	2.11
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.staff.science.uu.nl/~penni101/mirmon/

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Monitor the status of mirrors

NO_BUILD=	yes
USES=		perl5 shebangfix
USE_PERL5=	run

SHEBANG_FILES=	${WRKSRC}/mirmon ${WRKSRC}/probe

SUB_FILES=	pkg-message

PLIST_FILES=	bin/mirmon bin/probe

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

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
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} ${WRKSRC}/mirmon.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
