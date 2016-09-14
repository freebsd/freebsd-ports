# Created by: Mikolaj Golub <to.my.trociny@gmail.com>
# $FreeBSD$

PORTNAME=	gather
PORTVERSION=	0.4.1
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	Utility to store and display system statistics

LICENSE=	BSD2CLAUSE

BROKEN=		Unfetchable (google code has gone away)

PROJECTHOST=	gatherit

USES=		perl5

CONFLICTS_INSTALL=	harvest-[0-9]*

DATADIR=	/var/db/gather
MAKE_ENV+=	CONFDIR=${PREFIX}/etc/gather DATADIR=${DATADIR}

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gather ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gather.1 ${STAGEDIR}${PREFIX}/man/man1
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
