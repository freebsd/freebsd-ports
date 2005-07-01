# New ports collection Makefile for:    plb
# Date created:                         Feb 26, 2003
# Whom:                                 Frank Denis <j@pureftpd.org>
#
# $FreeBSD$
#

PORTNAME=	plb
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	http://plb.sunsite.dk/files/

MAINTAINER=	j@pureftpd.org
COMMENT=	A high-performance HTTP load balancer

BUILD_DEPENDS+=	${LOCALBASE}/lib/libevent.a:${PORTSDIR}/devel/libevent

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc

MAN8=		plb.8
DOCS=		AUTHORS CONTACT COPYING NEWS README THANKS TODO

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

.include <bsd.port.mk>
