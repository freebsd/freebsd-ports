# New ports collection makefile for:	rwhois
# Date created:				May 9th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rwhois
PORTVERSION=	1.5.7.3
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.rwhois.net/ftp/
DISTNAME=	${PORTNAME}d-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

.if !exists(/usr/include/tcpd.h)
LIB_DEPENDS=	wrap.7:${PORTSDIR}/security/tcp_wrapper
.endif

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}/lib/rwhois

BINOWN=		bin
BINGRP=		bin

MAN8=		rwhois_indexer.8 rwhoisd.8

PORTDOCS=	INSTALL.html TODO UPGRADE operations_guide.html \
		operations_guide.txt rfc2167.txt security.html security.txt

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/rwhois_indexer.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/doc/rwhoisd.8 ${PREFIX}/man/man8
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/rwhois
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${PREFIX}/share/doc/rwhois
.endfor
.endif
	@${ECHO_MSG} "Installing ${PREFIX}/etc/rc.d/rwhoisd.sh startup file..."
	${INSTALL_SCRIPT} -m 751 ${FILESDIR}/rwhoisd.sh ${PREFIX}/etc/rc.d/rwhoisd.sh

.include <bsd.port.mk>
