# Ports collection makefile for:  fastest_sites
# Date created:			  20 March 2008
# Whom:				  Wesley Shields <wxs@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fastest_sites
PORTVERSION=	20081104
PORTREVISION=	1
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://www.semicomplete.com/files/fastest_sites/
DISTNAME=	${PORTNAME}-${PORTVERSION}.py
EXTRACT_SUFX=	# nada

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Sort MASTER_SITE_* based upon TCP handshake times

USE_PYTHON=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/fastest_sites

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/local/bin/python#${PYTHON_CMD}#' ${WRKSRC}/fastest_sites-${PORTVERSION}.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/fastest_sites-${PORTVERSION}.py ${PREFIX}/bin/fastest_sites

.include <bsd.port.mk>
