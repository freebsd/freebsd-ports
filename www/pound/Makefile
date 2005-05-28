# New ports collection makefile for:	pound
# Date created:				27 August 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pound
PORTVERSION=	1.8.5
CATEGORIES=	www net
MASTER_SITES=	http://www.apsis.ch/pound/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/
DISTNAME=	Pound-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	anders@FreeBSD.org
COMMENT=	Reverse proxy, load balancer and HTTP(S) frontend for web servers

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes

CONFIGURE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
MAKE_ARGS+=	F_CONF=${PREFIX}/etc/pound.cfg

MAN8=	pound.8

post-install:
	@${ECHO} "===>  Installing ${PREFIX}/etc/rc.d/pound.sh"
	@${ECHO} "===>  startup file as ${PREFIX}/etc/rc.d/pound.sh.sample"
	@${INSTALL_SCRIPT} -m 751 ${FILESDIR}/pound.sh \
			${PREFIX}/etc/rc.d/pound.sh.sample
.include <bsd.port.mk>
