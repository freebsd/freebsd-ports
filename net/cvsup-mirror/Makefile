# New ports collection makefile for:	cvsup-mirror
# Version required:	none
# Date created:		01 February 1997
# Whom:			jdp
#
# $Id: Makefile,v 1.3 1997/07/13 18:49:27 max Exp $
#

DISTNAME=	cvsup-mirror-1.0
CATEGORIES=	net
DISTFILES=

MAINTAINER=	jdp@FreeBSD.org

RUN_DEPENDS=	${PREFIX}/sbin/cvsupd:${PORTSDIR}/net/cvsup

NO_WRKSUBDIR=	true
NO_CHECKSUM=	true
NO_BUILD=	true
IS_INTERACTIVE=	true
NO_PACKAGE=	too interactive
SCRIPTS_ENV=	USA_RESIDENT=${USA_RESIDENT}

base=${PREFIX}/etc/cvsup
rc=${PREFIX}/etc/rc.d

do-extract:
	@test -d ${WRKSRC} || ${MKDIR} ${WRKSRC}

do-install:
	@echo "Installing files"
	@test -d ${base} || mkdir -p ${base}
	@test -d ${rc} || mkdir -p ${rc}
	@${INSTALL_DATA} ${WRKSRC}/config.sh ${base}
	@${INSTALL_SCRIPT} ${FILESDIR}/update.sh ${base}
	@${INSTALL_DATA} ${FILESDIR}/supfile ${base}
	@${INSTALL_DATA} ${FILESDIR}/supfile.crypto ${base}
	@${INSTALL_DATA} ${FILESDIR}/supfile.non-crypto ${base}
	@${INSTALL_SCRIPT} ${FILESDIR}/cvsupd.sh ${rc}
	@${CP} /dev/null ${base}/.start_server

post-install:
	@PREFIX=${PREFIX} ${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
