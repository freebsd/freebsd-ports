# New ports collection makefile for:	clamsmtp
# Date created:		2004-07-29
# Whom:			Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	clamsmtp
PORTVERSION=	1.10
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://thewalter.net/stef/software/clamsmtp/

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	An ClamAV anti-virus SMTP Filter

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_RC_SUBR=	clamsmtpd
SUB_LIST=	CLAMAV_PID_DIR=${CLAMAV_PID_DIR}
SUB_FILES+=	pkg-message

CLAMAV_PID_DIR?=	/var/run/clamav

MAN5=		clamsmtpd.conf.5
MAN8=		clamsmtpd.8

PORTDOCS=	README

OPTIONS=	LOCAL_CLAMAV "RUN_DEPEND on security/clamav" on
OPTIONS+=	LOCAL_CLAMAV_DEVEL "RUN_DEPEND on security/clamav-devel" off

.include <bsd.port.pre.mk>

.if defined(WITH_LOCAL_CLAMAV)
RUN_DEPENDS+=	clamav>=0:${PORTSDIR}/security/clamav
.endif

.if defined(WITH_LOCAL_CLAMAV_DEVEL)
RUN_DEPENDS+=	clamav-devel>=0:${PORTSDIR}/security/clamav-devel
.endif

.if defined(WITH_LOCAL_CLAMAV) || defined(WITH_LOCAL_CLAMAV_DEVEL)
SUB_LIST+=	CLAMD=clamd
.else
SUB_LIST+=	CLAMD=
.endif

pre-extract:
.if defined(WITH_LOCAL_CLAMAV) && defined(WITH_LOCAL_CLAMAV_DEVEL)
	@${ECHO_CMD} "Please select only one clamav port"
	exit 1
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,%%PTHREAD_LIBS%%,${PTHREAD_LIBS}," ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s,/var/run/clamav/clamd,/var/run/clamav/clamd.sock," \
		${WRKSRC}/doc/clamsmtpd.conf \
		${WRKSRC}/doc/clamsmtpd.conf.5 \
		${WRKSRC}/src/clamsmtpd.c

post-install:
	@${INSTALL_DATA} ${WRKSRC}/doc/clamsmtpd.conf ${PREFIX}/etc/clamsmtpd.conf-sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/virus_action.sh ${EXAMPLESDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
