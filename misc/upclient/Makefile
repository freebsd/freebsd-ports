# Created by: Kelly Yancey <kbyanc@posi.net>
# $FreeBSD$

PORTNAME=	upclient
PORTVERSION=	5.0.b8
PORTREVISION=	7
CATEGORIES=	misc
MASTER_SITES=	http://uptimes.hostingwired.com/files/ \
		SF/${PORTNAME}/UpClient%205%20beta/5.0b8%20Security%20Update
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Uptimes project client

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext
USE_RC_SUBR=	upclient
ALL_TARGET=	bsd
BUILD_WRKSRC=	${WRKSRC}/src

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

REINPLACE_SUB=	PREFIX=${PREFIX} LOCALBASE=${LOCALBASE}

DOC_FILES=	AUTHORS COPYING FAQ HISTORY INSTALL README TODO
DOC_FILES+=	doc/UptimesProtocol5
DOC_FILES+=	HISTORY-BETA

OPTIONS_DEFINE=	DOCS

post-extract:
	@${MV} ${WRKSRC}/doc/"Uptimes Protocol 5" ${WRKSRC}/doc/UptimesProtocol5

post-patch:
	@${REINPLACE_CMD} ${REINPLACE_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/scripts/upchk ${WRKSRC}/scripts/clientchk \
		${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's|CC=gcc|CC="${CC}"|g' \
		${WRKSRC}/src/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/products/upclient \
		${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/src/products/upclient.8 \
		${STAGEDIR}${MAN8PREFIX}/man/man8
	${INSTALL_DATA} -m 640 ${WRKSRC}/src/products/upclient.conf \
		${STAGEDIR}${PREFIX}/etc/upclient.conf.sample
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/upchk ${WRKSRC}/scripts/clientchk \
		${STAGEDIR}${PREFIX}/sbin
	@(cd ${WRKSRC}/src; ${MAKE_CMD} destdir=${STAGEDIR} install-locales)

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
