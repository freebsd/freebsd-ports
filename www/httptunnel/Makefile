# New ports collection makefile for:    httptunnel
# Date created:         March 20 2000
# Whom:                 Brian Somers <brian@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	httptunnel
PORTVERSION=	3.3
CATEGORIES=	www
MASTER_SITES=	http://www.Awfulhak.org/httptunnel/ \
		ftp://ftp.nocrew.org/pub/nocrew/unix/ \
		http://www.nocrew.org/software/httptunnel/

MAINTAINER=	brian@FreeBSD.org

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--quiet
.if defined(ENABLE_DEBUG)
CONFIGURE_ARGS+=--enable-debug
.endif
MAN1=		hts.1 htc.1

post-install:
	${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${FILESDIR}/httptunnel.sh \
		>${PREFIX}/etc/rc.d/httptunnel.sh
	${CHMOD} 755 ${PREFIX}/etc/rc.d/httptunnel.sh

.include <bsd.port.mk>
