# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	shttpscanner
PORTVERSION=	0.4
CATEGORIES=	security www
MASTER_SITES=	SF/${PORTNAME}/sHTTPScanner/sHTTPScanner%20v${PORTVERSION}
DISTNAME=	sHTTPScanner_v${DISTVERSION}
EXTRACT_SUFX=	.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple HTTP scanner

USES=		dos2unix

PLIST_FILES=	bin/${PORTNAME} %%DATADIR%%/requests.txt %%DATADIR%%/subdomains.txt
PLIST_DIRS=	%%DATADIR%%

post-patch:
	@${REINPLACE_CMD} -E '/^#define/s!([a-z]*\.txt)!${DATADIR}/\1!' ${WRKSRC}/${DISTNAME:L}.c

do-build:
	@cd ${WRKSRC} && ${CC} ${CFLAGS} ${PTHREAD_CFLAGS} -o ${PORTNAME} ${DISTNAME:L}.c ${PTHREAD_LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@${INSTALL} -d ${STAGEDIR}${DATADIR}/
	${INSTALL} ${WRKSRC}/requests.txt ${WRKSRC}/subdomains.txt ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
