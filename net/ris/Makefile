# New ports collection makefile for:	ris
# Date created:		3 September 2005
# Whom:			Alex Deiter <tiamat@komi.mts.ru>
#
# $FreeBSD$
#

PORTNAME=	ris
PORTVERSION=	0.1
CATEGORIES=	net
MASTER_SITES=	http://oss.netfarm.it/guides/ \
		http://freebsd.komi.mtsnet.ru/ports/distfiles/
DISTNAME=	ris-linux

MAINTAINER=	tiamat@komi.mts.ru
COMMENT=	OpenSource alternative to Microsoft Windows RIS

RUN_DEPENDS=	${LOCALBASE}/libexec/in.tftpd:${PORTSDIR}/ftp/tftp-hpa

USE_RC_SUBR=	binlsrv.sh
USE_PYTHON=	yes
NO_BUILD=	yes

VARDIR=		${DESTDIR}/var
PID_FILE?=	${VARDIR}/run/binlsrv.pid
DEVLIST_CACHE?=	${VARDIR}/db/devlist.cache

PLIST_FILES=	sbin/binlsrv.py sbin/decode.py \
		sbin/fixloader.py sbin/infparser.py \
		sbin/fixup-repository.sh

SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} \
		PID_FILE=${PID_FILE} \
		DEVLIST_CACHE=${DEVLIST_CACHE}

post-patch:
.for SCRIPT in ${PLIST_FILES}
	@${REINPLACE_CMD} -e \
		's|@PYTHON_CMD@|${PYTHON_CMD}|; \
		s|@PID_FILE@|${PID_FILE}|; \
		s|@DEVLIST_CACHE@|${DEVLIST_CACHE}|' \
		${WRKSRC}/${SCRIPT:S/sbin\///}
.endfor

do-install:
.for SCRIPT in ${PLIST_FILES}
	${INSTALL_SCRIPT} ${WRKSRC}/${SCRIPT:S/sbin\///} ${PREFIX}/sbin
.endfor

.include <bsd.port.mk>
