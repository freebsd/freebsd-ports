# New ports collection makefile for:   qalculate
# Date created:        07 July 2004
# Whom:                Sergey Akifyev <asa@gascom.ru>
#
# $FreeBSD$
#

PORTNAME=	qalculate
PORTVERSION=	0.7.2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
#DISTNAME=	${PORTNAME}-gtk-${PORTVERSION}

MAINTAINER=	asa@agava.com
COMMENT=	Very powerful GUI calculator for GNOME

LIB_DEPENDS=	cln.3:${PORTSDIR}/math/cln
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot \
		wget:${PORTSDIR}/ftp/wget

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_INC_LIBTOOL_VER=15
USE_GNOME=	gnomeprefix gnomehack intlhack libglade2 libgnome
INSTALLS_OMF=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
# cln is built with gcc 3.4 on FreeBSD 4.x
USE_GCC=	3.4
# in FreeBSD 4.x struct liconv does not contain int_p_cs_precedes
EXTRA_PATCHES=	${FILESDIR}/extra-patch-FreeBSD4
.endif

.include <bsd.port.post.mk>
