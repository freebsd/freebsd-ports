# New ports collection makefile for:	netsaint
# Date created:				Wed 12 Jul 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	netsaint
PORTVERSION=	0.0.7b2
CATEGORIES=	net
MASTER_SITES=	http://netsaint.sourceforge.net/download/

MAINTAINER=	blaz@amis.net

LIB_DEPENDS=	gd.2:${PORTSDIR}/graphics/gd \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt
# no run depends due to circular reference
#RUN_DEPENDS=	${LOCALBASE}/libexec/netsaint/check_netsaint:${PORTSDIR}/net/netsaint-plugins

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lgd -lgnugetopt"
CONFIGURE_ARGS=	--with-command-user=root \
		--with-command-grp=wheel \
		--with-netsaint-user=netsaint \
		--with-netsaint-grp=netsaint
INSTALL_TARGET=	all install config install-config install-daemoninit

pre-fetch:
	@${SH} ${SCRIPTDIR}/checkps

pre-install:
	${PERL} ${SCRIPTDIR}/createuser

.include <bsd.port.mk>
