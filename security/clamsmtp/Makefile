# Created by: Cheng-Lung Sung <clsung@dragon2.net>
# $FreeBSD$

PORTNAME=	clamsmtp
PORTVERSION=	1.10
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	http://thewalter.net/stef/software/clamsmtp/

MAINTAINER=	yasu@utahime.org
COMMENT=	ClamAV anti-virus SMTP Filter

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		gmake
USE_RC_SUBR=	clamsmtpd
SUB_LIST=	CLAMAV_PID_DIR=${CLAMAV_PID_DIR}
SUB_FILES=	pkg-message

CLAMAV_PID_DIR?=/var/run/clamav

PORTDOCS=	README
PORTEXAMPLES=	*

OPTIONS_DEFINE=		DOCS LOCAL_CLAMAV EXAMPLES
OPTIONS_DEFAULT=	LOCAL_CLAMAV

LOCAL_CLAMAV_DESC=		RUN_DEPEND on security/clamav
LOCAL_CLAMAV_RUN_DEPENDS=	clamav>=0:security/clamav
LOCAL_CLAMAV_SUB_LIST=		CLAMD=clamd
LOCAL_CLAMAV_SUB_LIST_OFF=	CLAMD=

post-patch:
	@${REINPLACE_CMD} -e "s,/var/run/clamav/clamd,/var/run/clamav/clamd.sock," \
		${WRKSRC}/doc/clamsmtpd.conf \
		${WRKSRC}/doc/clamsmtpd.conf.5 \
		${WRKSRC}/src/clamsmtpd.c

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/clamsmtpd.conf ${STAGEDIR}${PREFIX}/etc/clamsmtpd.conf.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/virus_action.sh ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
