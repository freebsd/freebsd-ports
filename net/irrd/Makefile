# New ports collection makefile for:	irrd
# Date created:				Fri Apr  9 14:12:06 JST 2004
# Whom:					TAKANO Yuji <takano@usen.ad.jp>
#
# $FreeBSD$
#

PORTNAME=	irrd
PORTVERSION=	2.1.5
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.irrd.net/
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	takano@usen.ad.jp
COMMENT=	Internet Routing Registry database server

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}/src

MAN8=		irrd.8

IRRD_CONFDIR=	${PREFIX}/etc

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	YACC="${YACC}"
CONFIGURE_ARGS+=	--disable-thread

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.else
CONFIGURE_ARGS+=	--enable-ipv6
.endif

post-patch:
	${REINPLACE_CMD} -e 's|/etc/irrd.conf|${PREFIX}/etc/irrd.conf|g'	\
		${WRKSRC}/programs/IRRd/irrd.8				\
		${WRKSRC}/programs/IRRd/main.c				\
		${WRKSRC}/programs/hdr_comm/read_conf.c			\
		${WRKSRC}/programs/irr_notify/main.c			\
		${WRKSRC}/programs/irr_rpsl_check/main.c		\
		${WRKSRC}/programs/irr_submit/main.c			\
		${WRKSRC}/programs/irrdcacher/irrdcacher		\
		${WRKSRC}/programs/rps_dist/rpsdist.c

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/programs/irrdcacher/irrdcacher    ${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${WRKSRC}/programs/irrdcacher/ripe2rpsl     ${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${WRKSRC}/programs/irrdcacher/update_source ${PREFIX}/sbin
	@${INSTALL_DATA}   ${WRKSRC}/../samples/irrd.conf.sample       ${IRRD_CONFDIR}
	@${INSTALL_DATA}   ${WRKSRC}/programs/IRRd/irrd.8              ${PREFIX}/man/man8

.include <bsd.port.mk>
