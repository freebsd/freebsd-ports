# New ports collection makefile for:	qmail-conf
# Date created:		8 April 2003
# Whom:			roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	qmail-conf
PORTVERSION=	0.60
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.din.or.jp/~ushijima/qmail-conf/ \
		http://cr.yp.to/djbdns/
DISTFILES=	${DISTNAME}.tar.gz \
		${DJBDNS_DIST}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Configure various qmail services to run under daemontools

ALL_TARGET=	it
INSTALL_TARGET=	setup check

NO_PACKAGE=	"borrows code from djbdns, thus falls under the same restrictions as dns/djbdns"

# Note: this MUST be the same as the directory qmail is installed in!
QMAIL_DIR?=	/var/qmail
PREFIX?=	${QMAIL_DIR}

NO_MTREE=	yes

DJBDNS_VER=	1.05
DJBDNS_NAME=	djbdns-${DJBDNS_VER}
DJBDNS_DIST=	${DJBDNS_NAME}${EXTRACT_SUFX}

post-extract:
		@(cd ${WRKSRC} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DJBDNS_DIST} ${EXTRACT_AFTER_ARGS})

post-patch:
		@${ECHO_CMD} "${QMAIL_DIR}" > ${WRKSRC}/conf-qmail
		@${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
		@${ECHO_CMD} "${CC} ${CFLAGS} ${STRIP}" > ${WRKSRC}/conf-ld
		@${ECHO_CMD} "${LOCALBASE}" > ${WRKSRC}/conf-ucspi-tcp

pre-build:
		@(cd ${WRKSRC} && ${MAKE} djbdns=${DJBDNS_NAME} -f Makefile.ini)

.include <bsd.port.mk>
