PORTNAME=	fanout
PORTVERSION=	0.6.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.stearns.org/fanout/ \
		ftp://ftp.bascom.com/pub/wstearns/fanout/ \
		http://www.linuxgrill.com/anonymous/mirrors/wstearns/fanout/

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Tool to run commands on multiple machines

USES=		perl5
USE_PERL5=	run
NO_BUILD=	yes
PLIST_FILES=	bin/fanout bin/fanterm bin/fanmux
PORTDOCS=	README index.html

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},g' \
		${WRKSRC}/fanterm
	@${REINPLACE_CMD} -e 's,%%PERL%%,${PERL},g' \
		${WRKSRC}/fanmux

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/fanout ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/fanterm ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/fanmux ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
