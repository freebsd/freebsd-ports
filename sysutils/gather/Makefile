PORTNAME=	gather
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to store and display system statistics
WWW=		https://github.com/trociny/gather

LICENSE=	BSD2CLAUSE

USES=		perl5
USE_GITHUB=	yes

GH_ACCOUNT=	trociny

CONFLICTS_INSTALL=	harvest

DATADIR=	/var/db/gather
MAKE_ENV+=	CONFDIR=${PREFIX}/etc/gather DATADIR=${DATADIR}

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gather ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gather.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/gather
	${INSTALL_DATA} ${WRKSRC}/gather.cfg \
	    ${STAGEDIR}${PREFIX}/etc/gather/gather.cfg.sample
	${INSTALL_DATA} ${WRKSRC}/examples/gather.map.freebsd \
	    ${STAGEDIR}${PREFIX}/etc/gather/gather.map.sample
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Changelog ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/gather.map.freebsd \
	    ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/gather.map.linux \
	    ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
