PORTNAME=	rinetd
PORTVERSION=	0.62
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://www.boutell.com/rinetd/http/ \
		GENTOO
DISTNAME=	rinetd

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Simple TCP port redirector

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/rinetd-${PORTVERSION}

USES=		cpe dos2unix

PORTDOCS=	index.html
PLIST_FILES=	sbin/rinetd \
		man/man8/rinetd.8.gz

USE_RC_SUBR=	rinetd

post-extract:
	@${MV} ${WRKDIR}/rinetd ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -E "s,(/etc/rinetd.conf),${PREFIX}\1," \
		${WRKSRC}/rinetd.[8c]
	@${REINPLACE_CMD} -E "s,/usr(/sbin/rinetd),${PREFIX}\1," \
		${WRKSRC}/rinetd.8
	@${REINPLACE_CMD} -e "s,cc ,${CC} ,g" ${WRKSRC}/Makefile

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
