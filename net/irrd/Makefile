# New ports collection makefile for:	irrd
# Date created:				Fri Apr  9 14:12:06 JST 2004
# Whom:					TAKANO Yuji <takano@net-chef.net>
#
# $FreeBSD$
#

PORTNAME=	irrd
PORTVERSION=	2.3.10
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.irrd.net/
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Internet Routing Registry database server

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}/src

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

MAN8=		irrd.8

IRRD_CONFDIR=	${PREFIX}/etc

USE_RC_SUBR=	irrd
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	YACC="${YACC}"
#CONFIGURE_ARGS+=	--disable-thread

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.else
CONFIGURE_ARGS+=	--enable-ipv6
.endif

post-patch:
	${REINPLACE_CMD} -e 's|/etc/irrd.conf|${IRRD_CONFDIR}/irrd.conf|g' \
		${WRKSRC}/programs/IRRd/irrd.8	\
		${WRKSRC}/programs/IRRd/main.c	\
		${WRKSRC}/programs/irr_rpsl_submit/main.c	\
		${WRKSRC}/programs/irr_notify/main.c	\
		${WRKSRC}/programs/irr_rpsl_check/main.c	\
		${WRKSRC}/programs/rps_dist/rpsdist.c	\
		${WRKSRC}/programs/irrdcacher/irrdcacher	\
		${WRKSRC}/programs/hdr_comm/read_conf.c

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/programs/irrdcacher/irrdcacher    ${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${WRKSRC}/programs/irrdcacher/ripe2rpsl     ${PREFIX}/sbin
	@${INSTALL_DATA}   ${WRKSRC}/../samples/irrd.conf.sample       ${IRRD_CONFDIR}
	@${INSTALL_DATA}   ${WRKSRC}/programs/IRRd/irrd.8              ${PREFIX}/man/man8

.include <bsd.port.mk>
