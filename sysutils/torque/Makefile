# Created by: trasz
# $FreeBSD$

PORTNAME=	torque
PORTVERSION=	2.5.13
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	sysutils parallel
MASTER_SITES=	http://www.adaptivecomputing.com/index.php?wpfb_dl=1643/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source distributed computing resource manager based on PBS

FETCH_BEFORE_ARGS=	-o ${DISTDIR}/${DISTFILES}
USES=		gmake perl5 libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-syslog \
		--disable-spool
MAKE_ENV=	DESTDIR=${STAGEDIR}/${PREFIX}
USE_RC_SUBR=	pbs_server pbs_sched pbs_mom
SUB_FILES=	pkg-message torque-config
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFLICTS_INSTALL=	qstat-[0-9]* zh-qterm-[0-9]*

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.options.mk>

pre-configure:
	@${REINPLACE_CMD} -E 's|ps[ \t]+-ef|ps -ax|g' ${WRKSRC}/torque.setup
	@${REINPLACE_CMD} -E 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/configure

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/torque-config ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MEXAMPLES}
	${INSTALL_SCRIPT} ${WRKSRC}/torque.setup ${STAGEDIR}${EXAMPLESDIR}
.else
	${RM} -rf ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
