# New ports collection makefile for:	ris
# Date created:		3 September 2005
# Whom:			Alex Deiter <tiamat@komi.mts.ru>
#
# $FreeBSD$
#

PORTNAME=	ris
PORTVERSION=	0.4
CATEGORIES=	net
MASTER_SITES=	http://oss.netfarm.it/guides/
DISTNAME=	ris-linux-${PORTVERSION}

MAINTAINER=	alex.deiter@gmail.com
COMMENT=	OpenSource alternative to Microsoft Windows RIS

RUN_DEPENDS=	${LOCALBASE}/libexec/in.tftpd:${PORTSDIR}/ftp/tftp-hpa

USE_RC_SUBR=	binlsrv
USE_PYTHON=	yes
NO_BUILD=	yes

VARDIR=		/var
PID_FILE?=	${VARDIR}/run/binlsrv.pid
LOG_FILE?=	${VARDIR}/log/binlsrv.log
DEVLIST_CACHE?=	${VARDIR}/db/devlist.cache

SCRIPTS=	binlsrv.py decode.py		\
		fixloader.py hexdump.py		\
		infdump.py infparser.py		\
		modldr.py fixup-repository.sh


SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}	\
		PID_FILE=${PID_FILE}		\
		LOG_FILE=${LOG_FILE}		\
		DEVLIST_CACHE=${DEVLIST_CACHE}

post-patch:
.for SCRIPT in ${SCRIPTS}
	@${REINPLACE_CMD} -e \
		's|@PYTHON_CMD@|${PYTHON_CMD}|;		\
		s|@PID_FILE@|${PID_FILE}|;		\
		s|@LOG_FILE@|${LOG_FILE}|;		\
		s|@DEVLIST_CACHE@|${DEVLIST_CACHE}|'	\
		${WRKSRC}/${SCRIPT}
.endfor

do-install:
	@${MKDIR} ${DATADIR}/
	@${MKDIR} ${DATADIR}/inf
	@${MKDIR} ${DATADIR}/sys
	@${INSTALL_DATA} ${WRKSRC}/winnt.sif ${DATADIR}/
	@${INSTALL_DATA} ${FILESDIR}/tftp.map ${DATADIR}/
.for SCRIPT in ${SCRIPTS}
	@${INSTALL_SCRIPT} ${WRKSRC}/${SCRIPT} ${DATADIR}/
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
