# New ports collection makefile for:	cfengine
# Date created:		March 16, 1998
# Whom:			jseger@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cfengine
PORTVERSION=	1.6.3
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.iu.hio.no/pub/cfengine/ \
		ftp://ftp.sunsite.utk.edu/pub/cfengine/cfengine-ftp/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gordon@FreeBSD.org
COMMENT=	GNU cfengine - a systems administration tool for networks

.if defined(PACKAGE_BUILDING)
BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX
.endif

LIB_DEPENDS=	db3.3:${PORTSDIR}/databases/db3
.if defined(PACKAGE_BUILDING) && !exists(/usr/include/tcpd.h)
LIB_DEPENDS+=	wrap.7:${PORTSDIR}/security/tcp_wrapper
.endif

USE_GMAKE=	yes
USE_AUTOMAKE_VER=14

MAN8=		cfengine.8

pre-configure:
	@cd ${WRKSRC} && ${ACLOCAL} && ${AUTOHEADER}

post-install:
.if defined(NOPORTDOCS)
	@${RM} -rf ${PREFIX}/share/doc/${PORTNAME}
.endif

.include <bsd.port.mk>
