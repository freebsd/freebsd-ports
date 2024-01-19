PORTNAME=	rinetd
PORTVERSION=	0.73
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Simple TCP port redirector
WWW=		https://github.com/samhocevar/rinetd

LICENSE=	GPLv2

USES=		cpe dos2unix autoreconf
USE_GITHUB=	yes
GH_ACCOUNT=	samhocevar
GH_TAGNAME=	d4e0a60
USE_RC_SUBR=	rinetd

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PORTDOCS=	index.html

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -E \
			-e "s,(/etc/rinetd.conf),${PREFIX}\1," \
			-e "s,/usr(/sbin/rinetd),${PREFIX}\1," \
		${WRKSRC}/rinetd.8
	@${REINPLACE_CMD} -E "s,(/etc/rinetd.conf),${PREFIX}\1," \
		${WRKSRC}/src/rinetd.h

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/rinetd.conf \
		${STAGEDIR}${PREFIX}/etc/rinetd.conf.sample

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
