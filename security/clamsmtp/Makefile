# Created by: Cheng-Lung Sung <clsung@dragon2.net>
# $FreeBSD$

PORTNAME=	clamsmtp
PORTVERSION=	1.10
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://thewalter.net/stef/software/clamsmtp/

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	ClamAV anti-virus SMTP Filter

GNU_CONFIGURE=	yes
USES=		gmake
USE_RC_SUBR=	clamsmtpd
SUB_LIST=	CLAMAV_PID_DIR=${CLAMAV_PID_DIR}
SUB_FILES+=	pkg-message

CLAMAV_PID_DIR?=	/var/run/clamav

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS LOCAL_CLAMAV
OPTIONS_DEFAULT=	LOCAL_CLAMAV
LOCAL_CLAMAV_DESC=		RUN_DEPEND on security/clamav

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLOCAL_CLAMAV}
RUN_DEPENDS+=	clamav>=0:${PORTSDIR}/security/clamav
SUB_LIST+=	CLAMD=clamd
.else
SUB_LIST+=	CLAMD=
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,%%PTHREAD_LIBS%%,${PTHREAD_LIBS}," ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s,/var/run/clamav/clamd,/var/run/clamav/clamd.sock," \
		${WRKSRC}/doc/clamsmtpd.conf \
		${WRKSRC}/doc/clamsmtpd.conf.5 \
		${WRKSRC}/src/clamsmtpd.c

post-install:
	@${INSTALL_DATA} ${WRKSRC}/doc/clamsmtpd.conf ${STAGEDIR}${PREFIX}/etc/clamsmtpd.conf-sample
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/virus_action.sh ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
