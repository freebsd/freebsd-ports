# New ports collection makefile for:   openvmps
# Date created:        6 October 2003
# Whom:                Craig Boston <craig@yekse.gank.org>
#
# $FreeBSD$
#

PORTNAME=	openvmps
PORTVERSION=	1.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	vmps
DISTNAME=	vmpsd-${PORTVERSION}

MAINTAINER=	craig@yekse.gank.org
COMMENT=	A GPL implementation of the VMPS protocol

USE_RC_SUBR=	yes

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS=--bindir=${PREFIX}/sbin

RC_SCRIPTS_SUB=	PREFIX=${PREFIX} \
		RC_SUBR=${RC_SUBR}

post-install:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/vmpsd.sh > ${PREFIX}/etc/rc.d/vmpsd.sh
	@${CHMOD} 755 ${PREFIX}/etc/rc.d/vmpsd.sh
	${INSTALL_DATA} -m 644 ${FILESDIR}/vmps.db \
		${PREFIX}/etc/vmps.db.sample
	@if [ ! -f ${PREFIX}/etc/vmps.db ]; then \
		${CP} -p ${PREFIX}/etc/vmps.db.sample ${PREFIX}/etc/vmps.db ; \
	fi

.include <bsd.port.mk>
