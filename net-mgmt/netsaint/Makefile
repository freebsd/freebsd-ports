# New ports collection makefile for:	netsaint
# Date created:				Wed 12 Jul 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	netsaint
PORTVERSION=	0.0.7
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	http://netsaint.sourceforge.net/download/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=dwcjr
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} netsaint-graphics.tar.gz

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Extremely powerful network monitoring system

LIB_DEPENDS=	gd.2:${PORTSDIR}/graphics/gd \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt
RUN_DEPENDS=	${LOCALBASE}/libexec/netsaint/check_netsaint:${PORTSDIR}/net/netsaint-plugins

GNU_CONFIGURE=	yes
USE_PERL5=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lgd -lgnugetopt"
CONFIGURE_ARGS=	--with-command-user=netsaint \
		--with-command-grp=www \
		--with-netsaint-user=netsaint \
		--with-netsaint-grp=netsaint \
		--sbindir=${PREFIX}/share/netsaint/sbin \
		--libexecdir=${PREFIX}/libexec/netsaint \
		--datadir=${PREFIX}/share/netsaint \
		--sysconfdir=${PREFIX}/etc/netsaint \
		--localstatedir=${PREFIX}/var/netsaint

INSTALL_TARGET=	all install config install-config install-daemoninit install-commandmode

pre-fetch:
	@${SH} ${SCRIPTDIR}/checkps

pre-install:
	@PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

BSDIMAGES=	bsd_logofullsize.gif bsd_sblogo.gif

post-install:
.for i in ${BSDIMAGES}
	${INSTALL_DATA} ${WRKDIR}/netsaint-0.0.7b6/html/images/$i ${PREFIX}/share/${PORTNAME}/images/
.endfor

.include <bsd.port.mk>
