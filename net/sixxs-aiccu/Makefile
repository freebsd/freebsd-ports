# Created by: Meno Abels <meno.abels@adviser.com>
# $FreeBSD$

PORTNAME=	aiccu
PORTVERSION=	20070115
PORTREVISION=	3
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.sixxs.net/archive/sixxs/aiccu/unix/
PKGNAMEPREFIX=	sixxs-
DISTNAME=	aiccu_20070115

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	SixXS IPv6 TIC+ tunnel broker heartbeat client

LIB_DEPENDS=	gnutls-openssl:${PORTSDIR}/security/gnutls

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

USE_RC_SUBR=	sixxs-aiccu
USE_GMAKE=	yes

CFLAGS+=	${PTHREAD_CFLAGS} -D_REENTRANT -DAICCU_GNUTLS -I${LOCALBASE}/include
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib -lgnutls
MAKE_ARGS+=	CC="${CC}" LDFLAGS="${LDFLAGS}"
WRKSRC=		${WRKDIR}/aiccu
BUILD_WRKSRC=	${WRKDIR}/aiccu/unix-console
PORTDOCS=	README

OPTIONS_DEFINE=	LOG_DAEMON
LOG_DAEMON_DESC=	log to LOG_DAEMON instead to LOG_LOCAL7

post-patch:
	@${REINPLACE_CMD} \
		-e 's:verbose true:verbose false:' \
		-e 's:daemonize false:daemonize true:' \
		-e 's:automatic false:automatic true:' \
		-e 's:tunnel_id T2995:#tunnel_id TXXXX:' \
		-e 's:ipv4_interface eth0:ipv4_interface sis0:' \
		-e 's:ipv6_interface sixxs:ipv6_interface gif0:' \
		${WRKSRC}/doc/aiccu.conf

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLOG_DAEMON}
do-configure:
	@${REINPLACE_CMD} \
		-e 's:LOG_LOCAL7:LOG_DAEMON:' \
		${WRKSRC}/common/common.c
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unix-console/aiccu ${STAGEDIR}${PREFIX}/sbin/sixxs-aiccu
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README ${STAGEDIR}${DOCSDIR}/
.endif
	${INSTALL_DATA} ${WRKSRC}/doc/aiccu.conf ${STAGEDIR}${PREFIX}/etc/aiccu.conf.sample

.include <bsd.port.mk>
