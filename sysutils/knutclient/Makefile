# New ports collection makefile for:	KDE Nut Client
# Date created:				Mon Apr 28 05:30:59 UTC 2003
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	knutclient
PORTVERSION=	0.9.4
PORTREVISION=	1
CATEGORIES=	sysutils kde
MASTER_SITES=	ftp://ftp.buzuluk.cz/pub/alo/knutclient/stable/ \
		http://www.vg.kernel.org/pub/mirrors/gentoo/source/distfiles/

MAINTAINER=	rnejdl@ringofsaturn.com
COMMENT=	A visual client for UPS system NUT

BUILD_DEPENDS=	automake>=0:${PORTSDIR}/devel/automake19

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--disable-fast-perl --enable-mt --program-transform-name=''

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|-O2||' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e "/^ltmain=/!s^\$$ac_aux_dir/ltmain.sh^${LIBTOOLFLAGS} ${LTMAIN}^g" \
		-e '/^LIBTOOL=/s^\$$(top_builddir)/libtool^${LIBTOOL}^g' \
		${WRKSRC}/admin/libtool.m4.in

.include <bsd.port.mk>
