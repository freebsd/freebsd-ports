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

DEPRECATED=		EOL - consider using cfengine-2.x instead
EXPIRATION_DATE=	2005-09-14
NO_LATEST_LINK=		yes

.if defined(PACKAGE_BUILDING)
BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX
.endif

LIB_DEPENDS=	db3.3:${PORTSDIR}/databases/db3

USE_GMAKE=	yes
USE_AUTOMAKE_VER=14
USE_AUTOCONF_VER=213

MAN8=		cfengine.8

pre-configure:
	@cd ${WRKSRC} && ${ACLOCAL} && ${AUTOHEADER}

post-install:
.if defined(NOPORTDOCS)
	@${RM} -rf ${PREFIX}/share/doc/${PORTNAME}
.endif

.include <bsd.port.mk>
