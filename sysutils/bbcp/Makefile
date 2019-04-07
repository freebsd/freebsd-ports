# Created by: John Hein <jhein@symmetricom.com>
# $FreeBSD$

PORTNAME=	bbcp
PORTVERSION=	20150116
CATEGORIES=	sysutils net
MASTER_SITES=	http://BSDforge.com/projects/source/sysutils/bbcp/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Secure, fast, and IPv6 capable Copy utility

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/src/COPYING.LESSER

BROKEN=		fails to build
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2019-05-08

USES=		tar:xz

PLIST_FILES=	bin/bbcp
PORTDOCS=	${PORTNAME}.pdf

BUILD_WRKSRC=	${WRKSRC}/src

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|g++|${CXX}|' -e 's|gcc|${CC}|' \
		${WRKSRC}/src/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/FreeBSD/bbcp ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.pdf \
		${STAGEDIR}${DOCSDIR}/${PORTNAME}.pdf

.include <bsd.port.mk>
