# New ports collection makefile for:	mod_auth_external2
# Date created:				Fri Oct  10
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$

PORTNAME=	mod_auth_external
PORTVERSION=	2.2.6
CATEGORIES=	www
MASTER_SITES=	http://www.unixpapa.com/software/
DIST_SUBDIR=	apache

MAINTAINER=	sheeepkiller@cultdeadsheep.org
COMMENT=	Allows users authentication based on external mechanisms

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache2
RUN_DEPENDS=	${BUILD_DEPENDS}

LATEST_LINK=	mod_auth_external2

APXS?=		${LOCALBASE}/sbin/apxs

DOC_FILES=	AUTHENTICATORS INSTALL README
do-build:
	@(cd ${WRKSRC}/ && ${APXS} -I. -c ${PORTNAME}.c)

do-install:
	@(cd ${WRKSRC}/ && ${APXS} -A -i ${PORTNAME}.la)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.   for f in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.   endfor
.endif

.include <bsd.port.mk>
