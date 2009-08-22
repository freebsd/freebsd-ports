# New ports collection makefile for:	libdomainkeys
# Date created:	   16 May 2005
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	libdomainkeys
PORTVERSION=	0.69
CATEGORIES=	mail
MASTER_SITES=	SF/domainkeys/${PORTNAME}/${PORTVERSION}

MAINTAINER=	skv@FreeBSD.org
COMMENT=	DomainKeys library

USE_LDCONFIG=	YES
SHLIB_MAJOR=	3
PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"

USE_OPENSSL=	YES

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.prev
	@${SED} -e "s=%%SHLIB_MAJOR%%=${SHLIB_MAJOR}=g" \
		${FILESDIR}/Makefile > ${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/dknewkey ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/test ${DATADIR}/dktest

.include <bsd.port.mk>
