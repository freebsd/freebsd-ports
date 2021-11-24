# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>

PORTNAME=	shttpscanner
PORTVERSION=	0.4
CATEGORIES=	security www
MASTER_SITES=	SF/${PORTNAME}/sHTTPScanner/sHTTPScanner%20v${PORTVERSION}
DISTNAME=	sHTTPScanner_v${DISTVERSION}
EXTRACT_SUFX=	.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple HTTP scanner

DEPRECATED=	Abandonware, last release in 2006
EXPIRATION_DATE=2022-03-31

USES=		dos2unix

PLIST_FILES=	bin/${PORTNAME} \
		%%DATADIR%%/requests.txt \
		%%DATADIR%%/subdomains.txt

post-patch:
	@${REINPLACE_CMD} -E '/^#define/s!([a-z]*\.txt)!${DATADIR}/\1!' \
		${WRKSRC}/${DISTNAME:tl}.c

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${CC} ${CFLAGS} -o ${PORTNAME} ${DISTNAME:tl}.c -lpthread)

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL} ${WRKSRC}/requests.txt ${WRKSRC}/subdomains.txt \
		${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
