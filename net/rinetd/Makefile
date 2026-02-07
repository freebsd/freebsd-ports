PORTNAME=	rinetd
PORTVERSION=	0.62
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	net

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Simple TCP port redirector
WWW=		https://github.com/samhocevar/rinetd

LICENSE=	GPLv2

USES=		cpe dos2unix
USE_GITHUB=	yes
GH_ACCOUNT=	samhocevar
GH_TAGNAME=	1c95abb27dbf3
USE_RC_SUBR=	rinetd

PLIST_FILES=	sbin/rinetd \
		share/man/man8/rinetd.8.gz
PORTDOCS=	index.html

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -E \
			-e "s,(/etc/rinetd.conf),${PREFIX}\1," \
			-e "s,/usr(/sbin/rinetd),${PREFIX}\1," \
		${WRKSRC}/rinetd.8
	@${REINPLACE_CMD} -E "s,(/etc/rinetd.conf),${PREFIX}\1," \
		${WRKSRC}/rinetd.c
	@${REINPLACE_CMD} -e "s,cc ,${CC} ,g" ${WRKSRC}/Makefile

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
