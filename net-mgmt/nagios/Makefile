# New ports collection makefile for:	netsaint
# Date created:				Wed 12 Jul 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	netsaint
PORTVERSION=	0.0.7b3
CATEGORIES=	net
MASTER_SITES=	http://netsaint.sourceforge.net/download/

MAINTAINER=	blaz@amis.net

LIB_DEPENDS=	gd.2:${PORTSDIR}/graphics/gd \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt
RUN_DEPENDS=	${LOCALBASE}/libexec/netsaint/check_netsaint:${PORTSDIR}/net/netsaint-plugins

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lgd -lgnugetopt"
CONFIGURE_ARGS=	--with-command-user=nobody \
		--with-command-grp=nogroup \
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
	${PERL} ${SCRIPTDIR}/createuser

.include <bsd.port.mk>
