# New ports collection makefile for:	xfmail
# Date created:		30 June 1996
# Whom:			gena
#
# $FreeBSD$
#

PORTNAME=	xfmail
PORTVERSION=	1.5.3
CATEGORIES=	mail
MASTER_SITES=	ftp://xfmail.ufies.org/pub/xfmail/release/%SUBDIR%/	       \
		ftp://cupido.geophys.nat.tu-bs.de/pub/xfmail/release/%SUBDIR%/ \
		ftp://ftp.cfreeze.com/pub/xfmail/release/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}/source/

MAINTAINER=	mikeh@FreeBSD.org

BUILD_DEPENDS+=	autoconf:${PORTSDIR}/devel/autoconf

LIB_DEPENDS=	forms.1:${PORTSDIR}/x11-toolkits/xforms \
		gdbm.2:${PORTSDIR}/databases/gdbm

USE_AUTOMAKE_VER=	15
USE_AUTOCONF=	yes
USE_BZIP2=	yes
USE_GNOMENG=	yes
USE_GNOME=	glib12
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes

AUTOCONF=	autoconf
AUTOHEADER=	autoheader
ACLOCAL=	aclocal

# XXX: Disable patching for libtool until we can generate the files
LIBTOOLFILES=

.include <bsd.port.pre.mk>

CONFIGURE_ARGS=	--with-dbm-lib=gdbm

.if defined(WITH_ESOUND)
USE_ESOUND=	yes
CONFIGURE_ARGS+=	--with-esd-sound
.endif

MAN1=		xfmail.1

pre-configure:
	@(cd ${WRKSRC} && ${SH} autogen.sh);	\
	${MAKE} LIBTOOLFILES=aclocal.m4 patch-libtool

.include <bsd.port.post.mk>
