# Created by: Kimo <kimor79@yahoo.com>
# $FreeBSD$

PORTNAME=	mod_auth_cas
PORTVERSION=	1.0.9.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://source.jasig.org/cas-clients/mod_auth_cas/tags/mod_auth_cas-${PORTVERSION}/src/
# SVN tags only, *sigh*
DISTFILES=	mod_auth_cas.c mod_auth_cas.h
DIST_SUBDIR=	apache2/mod_auth_cas/${PORTVERSION}
EXTRACT_ONLY=

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache 2.x module that supports the CASv1 and CASv2 protocols

LICENSE=	AL2

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl

NO_WRKSUBDIR=	yes

USE_APACHE=	22+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
AP_LIB=		${LOCALBASE}/lib
AP_EXTRAS=	-l ssl -l curl

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/mod_auth_cas.c ${WRKSRC}/mod_auth_cas.c
	${CP} ${DISTDIR}/${DIST_SUBDIR}/mod_auth_cas.h ${WRKSRC}/mod_auth_cas.h

.include <bsd.port.mk>
