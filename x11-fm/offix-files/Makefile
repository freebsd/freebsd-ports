# ports collection makefile for: Files
# Date created:      28 Jun 1997
# Whom:              Ruslan Shevchenko <ruslan@shevchenko.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	offix-files
PORTVERSION=	2.4
PORTREVISION=	1
CATEGORIES=	x11-fm
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	desktop_managers/OffiX
DISTNAME=	Files-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File bar from OffiX

DEPRECATED=	development ceased in 1996
EXPIRATION_DATE=2006-11-05

RUN_DEPENDS=	execute:${PORTSDIR}/x11/offix-execute \
		editor:${PORTSDIR}/editors/offix-editor

LIB_DEPENDS=	Dnd.1:${PORTSDIR}/x11/libdnd

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X_PREFIX=	YES
USE_XPM=	YES
MAN1=		files.1
MAN3=		regexp.3

post-install:
	@${INSTALL_DATA} ${WRKSRC}/src/Files.ad ${PREFIX}/share/OffiX/

.include <bsd.port.mk>
