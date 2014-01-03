# Created by: John Hein <jhein@symmetricom.com>
# $FreeBSD$

PORTNAME=	bbcp
PORTVERSION=	20120520
CATEGORIES=	sysutils net
MASTER_SITES=	https://bitbucket.org/jhein/bbcp/downloads/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${PORTNAME}-20100818.pdf
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jhein@symmetricom.com
COMMENT=	Secure and fast copy utility

LICENSE=	BSD

BUILD_WRKSRC=	${WRKSRC}/src
PLIST_FILES=	bin/bbcp
PORTDOCS=	${PORTNAME}.pdf
USE_XZ=		yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/FreeBSD/bbcp ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}-20100818.pdf ${DOCSDIR}/${PORTNAME}.pdf
.endif

.include <bsd.port.mk>
