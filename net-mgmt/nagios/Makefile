# New ports collection makefile for:	nagios
# Date created:				19 May 2002
# Whom:					Blaz Zupan <blaz@si.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nagios
PORTVERSION=	1.0.b6
PORTREVISION=	0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=nagios
DISTNAME=	nagios-1.0b6

MAINTAINER=	blaz@si.FreeBSD.org

LIB_DEPENDS=	gd.2:${PORTSDIR}/graphics/gd \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt
RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:${PORTSDIR}/net/nagios-plugins

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lgd -lgnugetopt"
CONFIGURE_ARGS=	--with-command-user=nagios \
		--with-command-grp=www \
		--with-nagios-user=nagios \
		--with-nagios-grp=nagios \
		--with-template-objects \
		--with-template-extinfo \
		--with-init-dir=${PREFIX}/etc/rc.d \
		--sbindir=${PREFIX}/share/nagios/cgi-bin \
		--libexecdir=${PREFIX}/libexec/nagios \
		--datadir=${PREFIX}/share/nagios \
		--sysconfdir=${PREFIX}/etc/nagios \
		--localstatedir=${PREFIX}/var/nagios \
		--prefix=${PREFIX}

INSTALL_TARGET=	all install config install-config install-daemoninit install-commandmode

pre-fetch:
	@${SH} ${SCRIPTDIR}/checkps

pre-install:
	@PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

.include <bsd.port.mk>
