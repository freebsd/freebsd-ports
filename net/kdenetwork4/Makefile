# -*-mode: makefile-*-
# New ports collection makefile for:	kdenetwork2
# Date created:				2 November 2001
# Whom:					will@cvs.kde.org
#
# $FreeBSD$
#

PORTNAME=	kdenetwork
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	1
CATEGORIES?=	net kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org
COMMENT=	Network-related programs and modules for KDE

LIB_DEPENDS=	slp:${PORTSDIR}/net/openslp

CONFLICTS=	kopete-[0-9]*

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_PERL5=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

pre-configure:
.if ${OSVERSION} < 500028
	@${REINPLACE_CMD} -e 's|stdint.h|inttypes.h|g' \
		${WRKSRC}/kopete/protocols/gadu/libgadu/libgadu-config.h.in
.endif

.include <bsd.port.post.mk>
