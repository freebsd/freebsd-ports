# New ports collection Makefile for:    plb
# Date created:                         Feb 26, 2003
# Whom:                                 Frank Denis <j@pureftpd.org>
#
# $FreeBSD$
#

PORTNAME=	plb
PORTVERSION=	0.3
PORTREVISION=	3
CATEGORIES=	net ipv6
MASTER_SITES=	http://plb.sunsite.dk/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A high-performance HTTP load balancer

LIB_DEPENDS=	event-1.3b:${PORTSDIR}/devel/libevent

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc

MAN8=		plb.8
DOCS=		AUTHORS CONTACT COPYING NEWS README THANKS TODO

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2
.endif

post-extract:
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=g" ${FILESDIR}/plb.sh.sample \
		> ${WRKSRC}/plb.sh.sample

post-install:
	${INSTALL_DATA} ${WRKSRC}/plb.conf ${PREFIX}/etc/plb.conf.sample
	${INSTALL_SCRIPT} ${WRKSRC}/plb.sh.sample ${PREFIX}/etc/rc.d/plb.sh.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/plb
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${PREFIX}/share/doc/plb)
.endif
	@${ECHO_CMD}
	@${ECHO_CMD} "Now you need to examine ${PREFIX}/etc/plb.conf.sample,"
	@${ECHO_CMD} "to adapt it to your needs, and save it as ${PREFIX}/etc/plb.conf.sample."
	@${ECHO_CMD}

.include <bsd.port.post.mk>
