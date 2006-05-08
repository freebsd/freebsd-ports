# New ports collection makefile for:   emelfm2
# Date created:        01 Novemeber 2003
# Whom:                Marcus von Appen
#
# $FreeBSD$
#

PORTNAME=	emelfm2
PORTVERSION=	0.1.7
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.emelfm2.net/rel/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ehaupt

MAINTAINER=	mva@sysfault.org
COMMENT=	The gtk2 port of emelfm, a fast graphical filemanager

USE_GNOME=	gtk20
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GETOPT_LONG=yes
INSTALLS_SHLIB=	yes
INSTALL_TARGET=	install install_i18n

MAKE_ENV=	CC=${CC} LDFLAGS="${LDFLAGS}" DOC_DIR="${DOCSDIR}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
USE_GCC=	3.4
.endif

.include <bsd.port.post.mk>
