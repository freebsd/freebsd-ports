# New ports collection makefile for:	qtools
# Date created:				3 July 2001
# Whom:					petef@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	qtools
PORTVERSION=	0.56
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.superscript.com/qtools/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Tools to use in .qmail files

RUN_DEPENDS=	${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail \
		${EZMLM_DIR}/bin/ezmlm-weed:${PORTSDIR}/mail/ezmlm

ALL_TARGET=	it
INSTALL_TARGET=	setup check

QMAIL_DIR?=	/var/qmail
EZMLM_DIR?=	${LOCALBASE}

do-configure:
	@${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	@${ECHO_CMD} "${CC} ${STRIP}" > ${WRKSRC}/conf-ld
	@${ECHO_CMD} "${PREFIX}" > ${WRKSRC}/conf-home
	@${ECHO_CMD} "${QMAIL_DIR}" > ${WRKSRC}/conf-qmail
	@${ECHO_CMD} "${EZMLM_DIR}/bin/ezmlm" > ${WRKSRC}/conf-ezmlm

.include <bsd.port.mk>
