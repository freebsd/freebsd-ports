# Ports collection makefile for:  xmlcatmgr
# Date created:			  Sat May 24, 2003
# Whom:				  Hiroki Sato <hrs@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmlcatmgr
PORTVERSION=	1.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	SGML and XML catalog manager

BUILD_DEPENDS=	buildtool:${PORTSDIR}/devel/buildtool

MAN1=		xmlcatmgr.1

do-configure:
	cd ${WRKSRC} && buildtool config -p ${PREFIX} \
		--dir-catalog=${PREFIX}/share/xml \
		--dir-doc=${DOCSDIR}

do-build:
	cd ${WRKSRC} && buildtool build

do-install:
	cd ${WRKSRC} && buildtool install
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
