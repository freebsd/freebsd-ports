# New ports collection makefile for:	libgpg-error
# Date created:		2003-10-12
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	libgpg-error
PORTVERSION=	0.6
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	alpha/${PORTNAME}

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Common error values for all GnuPG components

USE_GPG=	yes
USE_LIBTOOL_VER=13
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

DOCS=		AUTHORS ChangeLog NEWS README

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
