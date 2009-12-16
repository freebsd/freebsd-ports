# New ports collection Makefile for:    plb
# Date created:                         Feb 26, 2003
# Whom:                                 Frank Denis <j@pureftpd.org>
#
# $FreeBSD$
#

PORTNAME=	plb
PORTVERSION=	0.3
PORTREVISION=	7
CATEGORIES=	net ipv6
MASTER_SITES=	http://plb.sunsite.dk/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A high-performance HTTP load balancer

LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent

BROKEN=		does not build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc

USE_RC_SUBR=	${PORTNAME}

MAN8=		plb.8
DOCS=		AUTHORS CONTACT COPYING NEWS README THANKS TODO

.include <bsd.port.pre.mk>

post-install:
	${INSTALL_DATA} ${WRKSRC}/plb.conf ${PREFIX}/etc/plb.conf.sample
	@if [ ! -f ${PREFIX}/etc/plb.conf ]; then \
		${CP} -p ${PREFIX}/etc/plb.conf.sample ${PREFIX}/etc/plb.conf ; \
	fi
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}/)
.endif

.include <bsd.port.post.mk>
