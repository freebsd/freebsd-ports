# $FreeBSD$

PORTNAME=	ubuntu-keyring
PORTVERSION=	2020.06.17.1
CATEGORIES=	security
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	GPG keys for Ubuntu package signature verification

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/debian/copyright

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/keyrings
	${INSTALL_DATA} ${WRKSRC}/keyrings/* ${STAGEDIR}${PREFIX}/share/keyrings/

.include <bsd.port.mk>
