# New ports collection makefile for: qscan
# Date created:		8 Apr 2004
# Whom:			Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qscan
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	mail security
MASTER_SITES=	ftp://ftp.c9x.org/qscan/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A mail filter for Qmail that scans messages with ClamAV

RUN_DEPENDS=	clamdscan:${PORTSDIR}/security/clamav \
		ripmime:${PORTSDIR}/mail/ripmime
USE_QMAIL_RUN=	yes

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

QMAIL_QUEUE=	${QMAIL_PREFIX}/bin/qmail-queue
QSCAN_VAR?=	${QMAIL_PREFIX}/${PORTNAME}
PLIST_SUB+=	QSCAN_VAR="${QSCAN_VAR}" \
		QMAIL_QUEUE="${QMAIL_QUEUE}"

# default 10
.if defined(WITH_CONCURRENCY)
CONFIGURE_ARGS+=--with-concurrency=${WITH_CONCURRENCY}
.endif

CONFIGURE_ENV+=	SWEEP="${LOCALBASE}/bin/clamdscan" \
		RIPMIME="${LOCALBASE}/bin/ripmime" \
		QMAIL_QUEUE="${QMAIL_QUEUE}-old"

post-patch:
	@${REINPLACE_CMD} -e "s|/var/qmail/qscan|${QSCAN_VAR}|" ${WRKSRC}/src/qscan.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${QSCAN_VAR}
	${CHMOD} 750 ${QSCAN_VAR}
	${CHOWN} qmaild:clamav ${QSCAN_VAR}
	${LN} -f ${QMAIL_QUEUE} ${QMAIL_QUEUE}-old
	${LN} -sf ${PREFIX}/bin/${PORTNAME} ${QMAIL_QUEUE}

.include <bsd.port.post.mk>
