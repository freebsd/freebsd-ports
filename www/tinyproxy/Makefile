# New ports collection makefile for:	tinyproxy
# Date created:		01 Jul 1999
# Whom:			Mitsuru Yoshida <mitsuru@riken.go.jp>
#
# $FreeBSD$
#

PORTNAME=	tinyproxy
PORTVERSION=	1.6.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	so14k@so14k.com
COMMENT=	A small, efficient HTTP proxy server

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--bindir=${PREFIX}/sbin --with-config=${PREFIX}/etc/tinyproxy/tinyproxy.conf --program-transform-name=""

MAN8=		tinyproxy.8

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e s:/etc/tinyproxy/tinyproxy.conf:${PREFIX}/etc/tinyproxy/tinyproxy.conf: \
	  ${WRKSRC}/doc/tinyproxy.8
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|stdint.h|stdlib.h|' ${WRKSRC}/src/scanner.c
.endif

post-install:
	@${SED} -e "s#%PREFIX%#${PREFIX}#" ${FILESDIR}/tinyproxy.sh > ${WRKDIR}/tinyproxy.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/tinyproxy.sh ${LOCALBASE}/etc/rc.d
	@${SED} -e "s#/usr/local/#${LOCALBASE}/#" ${PKGMESSAGE}

.include <bsd.port.post.mk>
