# New ports collection makefile for:    httptunnel
# Date created:         March 20 2000
# Whom:                 Brian Somers <brian@Awfulhak.org>
#
# $FreeBSD$
#

PORTNAME=	httptunnel
PORTVERSION= 	3.0
CATEGORIES=	net
MASTER_SITES=	http://www.Awfulhak.org/httptunnel/ \
		ftp://ftp.nocrew.org/pub/nocrew/unix/ \
		http://www.nocrew.org/software/httptunnel/

MAINTAINER=	brian@Awfulhak.org

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--quiet
MAN1=		hts.1 htc.1

post-install:
	[ -f ${PREFIX}/etc/rc.d/httptunnel.sh ] || \
		${INSTALL_SCRIPT} ${FILESDIR}/httptunnel.sh ${PREFIX}/etc/rc.d/.

.include <bsd.port.mk>
