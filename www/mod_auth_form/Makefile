# Created by: Tommy Scheunemann <net@arrishq.net>
# $FreeBSD$

PORTNAME=	mod_auth_form
PORTVERSION=	2.05
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://comp.uark.edu/~ajarthu/mod_auth_form/download.php?download=v2_05/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	net@arrishq.net
COMMENT=	MySQL based form authentication module for Apache 2.x


WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_MYSQL=	yes
USE_APACHE=	22

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MYSQL_PREFIX="${LOCALBASE}" APACHE2_PREFIX="${LOCALBASE}" \
		APACHE2_INCLUDE="${LOCALBASE}/include/apache${APACHE_VERSION}" \
		APR1_INCLUDE="${LOCALBASE}/include/apache2"

CFLAGS+=	-I${LOCALBASE}/include

PORTDOCS=	AUTHORS NEWS README

post-install:
	${ECHO} ${APACHE_VERSION}
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
