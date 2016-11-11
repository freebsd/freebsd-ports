# Created by: Meno Abels <meno.abels@adviser.com>
# $FreeBSD$

PORTNAME=	aiccu
PORTVERSION=	20070115
PORTREVISION=	5
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.sixxs.net/archive/sixxs/aiccu/unix/
PKGNAMEPREFIX=	sixxs-
DISTNAME=	aiccu_20070115

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SixXS IPv6 TIC+ tunnel broker heartbeat client

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

WRKSRC=		${WRKDIR}/aiccu
BUILD_WRKSRC=	${WRKDIR}/aiccu/unix-console

USE_RC_SUBR=	sixxs-aiccu
USES=		gmake
MAKE_ARGS=	CC="${CC}" LDFLAGS="${LDFLAGS}"
CFLAGS+=	-D_REENTRANT -I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib

PORTDOCS=	README

OPTIONS_DEFINE=	GNUTLS LOG_DAEMON DOCS
OPTIONS_DEFAULT=	GNUTLS

GNUTLS_DESC=	Use gnutls to secure TIC supporting starttls
LOG_DAEMON_DESC=Log to LOG_DAEMON instead to LOG_LOCAL7

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CFLAGS=		-DAICCU_GNUTLS
GNUTLS_LDFLAGS=		-lgnutls

post-patch:
	@${REINPLACE_CMD} \
		-e 's:verbose true:verbose false:' \
		-e 's:daemonize false:daemonize true:' \
		-e 's:automatic false:automatic true:' \
		-e 's:tunnel_id T2995:#tunnel_id TXXXX:' \
		-e 's:ipv4_interface eth0:ipv4_interface sis0:' \
		-e 's:ipv6_interface sixxs:ipv6_interface gif0:' \
		${WRKSRC}/doc/aiccu.conf

post-patch-LOG_DAEMON-on:
	@${REINPLACE_CMD} \
		-e 's:LOG_LOCAL7:LOG_DAEMON:' \
		${WRKSRC}/common/common.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unix-console/aiccu ${STAGEDIR}${PREFIX}/sbin/sixxs-aiccu
	${INSTALL_DATA} ${WRKSRC}/doc/aiccu.conf ${STAGEDIR}${PREFIX}/etc/aiccu.conf.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
