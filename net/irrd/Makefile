# Created by: TAKANO Yuji <takano@net-chef.net>
# $FreeBSD$

PORTNAME=	irrd
PORTVERSION=	2.3.10
PORTREVISION=	2
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.irrd.net/
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Internet Routing Registry database server

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}/src

IRRD_CONFDIR=	${PREFIX}/etc

USES=		shebangfix
USE_RC_SUBR=	irrd
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	YACC="${YACC}"
MAKE_JOBS_UNSAFE=	yes
#CONFIGURE_ARGS+=	--disable-thread
DESTDIRNAME=	STAGEDIR

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.else
CONFIGURE_ARGS+=	--enable-ipv6
.endif

SHEBANG_FILES=	programs/irrdcacher/irrdcacher \
		programs/irrdcacher/ripe2rpsl

PLIST_FILES=	etc/irrd.conf.sample \
		man/man8/irrd.8.gz \
		sbin/irr_notify \
		sbin/irr_rpsl_check \
		sbin/irr_rpsl_submit \
		sbin/irrd \
		sbin/irrdcacher \
		sbin/ripe2rpsl

post-patch:
	${REINPLACE_CMD} -e 's|/etc/irrd.conf|${IRRD_CONFDIR}/irrd.conf|g' \
		${WRKSRC}/programs/IRRd/irrd.8 \
		${WRKSRC}/programs/IRRd/main.c \
		${WRKSRC}/programs/hdr_comm/read_conf.c \
		${WRKSRC}/programs/irr_notify/main.c \
		${WRKSRC}/programs/irr_rpsl_check/main.c \
		${WRKSRC}/programs/irr_rpsl_submit/main.c \
		${WRKSRC}/programs/irrdcacher/irrdcacher \
		${WRKSRC}/programs/rps_dist/rpsdist.c
	${REINPLACE_CMD} -e 's|\($$(DESTDIR)\)|$$(STAGEDIR)\1|g' \
		-e 's|\( -m 755 \)| -s\1|g' \
		-e 's| -o root -g bin||g' \
		${WRKSRC}/programs/IRRd/Makefile \
		${WRKSRC}/programs/irr_notify/Makefile \
		${WRKSRC}/programs/irr_rpsl_check/Makefile \
		${WRKSRC}/programs/irr_rpsl_submit/Makefile

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/programs/irrdcacher/irrdcacher \
		${STAGEDIR}${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${WRKSRC}/programs/irrdcacher/ripe2rpsl \
		${STAGEDIR}${PREFIX}/sbin
	@${INSTALL_DATA} ${WRKSRC}/../samples/irrd.conf.sample \
		${STAGEDIR}${IRRD_CONFDIR}
	@${INSTALL_DATA} ${WRKSRC}/programs/IRRd/irrd.8 \
		${STAGEDIR}${PREFIX}/man/man8

.include <bsd.port.mk>
