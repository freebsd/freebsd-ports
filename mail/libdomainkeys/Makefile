# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	libdomainkeys
PORTVERSION=	0.69
CATEGORIES=	mail
MASTER_SITES=	SF/domainkeys/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DomainKeys library

USES=		uidfix
USE_LDCONFIG=	yes
SHLIB_MAJOR=	3
PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"
MAKE_ENV=	SHLIB_MAJOR="${SHLIB_MAJOR}"

USE_OPENSSL=	yes

post-patch:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/dknewkey ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/test ${STAGEDIR}${DATADIR}/dktest

.include <bsd.port.mk>
