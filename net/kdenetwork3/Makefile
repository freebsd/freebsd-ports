# -*-mode: makefile-*-
# New ports collection makefile for:	kdenetwork2
# Date created:				2 November 2001
# Whom:					will@cvs.kde.org
#
# $FreeBSD$
#

PORTNAME=	kdenetwork
PORTVERSION=	${KDE_VERSION}
CATEGORIES?=	net kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org
COMMENT=	Network-related programs and modules for KDE

LIB_DEPENDS=	slp:${PORTSDIR}/net/openslp

OPTIONS=	KOPETE	"Install kopete multi-protocol instant messenger" OFF

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_PERL5=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes

USE_AUTOTOOLS=  libtool:15
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3
DO_NOT_COMPILE+=kopete lanbrowsing

CONFIGURE_ARGS+=--with-ssl-dir=${OPENSSLBASE}

.if defined(DO_NOT_COMPILE)
CONFIGURE_ENV+=DO_NOT_COMPILE="${DO_NOT_COMPILE}"
.endif # defined(DO_NOT_COMPILE)

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

pre-configure:
	@${REINPLACE_CMD} \
	-E -e '/^SUBDIRS/s/lisa//g' \
		${WRKSRC}/doc/Makefile.in

##
# OPTIONS handling
##
#
.if defined(WITH_KOPETE)
RUN_DEPENDS+=	kopete:${PORTSDIR}/net-im/kopete
.endif

.include <bsd.port.post.mk>
