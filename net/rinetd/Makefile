# Created by: alexp
# $FreeBSD$

PORTNAME=	rinetd
PORTVERSION=	0.62
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://www.boutell.com/rinetd/http/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
DISTNAME=	rinetd

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A simple TCP port redirector

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/rinetd-${PORTVERSION}

USE_DOS2UNIX=	yes

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
	@${REINPLACE_CMD} -e "s/cc /${CC} /g" ${WRKSRC}/Makefile

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
