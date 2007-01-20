# New ports collection makefile for:	xneur
# Date created:		19 January 2007
# Whom:			Alex "lissyara" Keda <admin@lissyara.su>
#
# $FreeBSD$
#

PORTNAME=	XNeur
PORTVERSION=	0.3
CATEGORIES=	russian
MASTER_SITES=	http://dists.xneur.ru/release-0.3.0/tgz/ CSME

MAINTAINER=	admin@lissyara.su
COMMENT=	Auto keyboard switcher

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USE_XLIB=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e '/chmod/s|a\+|u+|' ${WRKSRC}/etc/Makefile.in
	@${REINPLACE_CMD} -e '/^am__strip_dir/s#`;#|sed -Ee "s/^(xneurrc|dict)$$$$/\\1.dist/"`;#' \
		${WRKSRC}/etc/Makefile.in ${WRKSRC}/etc/*/Makefile.in

post-install:
	@for i in ${PREFIX}/etc/xneur/*.dist ${PREFIX}/etc/xneur/*/*.dist;\
		do ${CP} -np $$i $${i%.dist}; done

.include <bsd.port.mk>
