# New ports collection makefile for:	oops
# Date created:		15 August 2000
# Whom:			Sergey Osokin aka oZZ <ozz@FreeBSD.org.ru>
#
# $FreeBSD$
#

PORTNAME=	oops
PORTVERSION=	1.4.16
CATEGORIES=	www
MASTER_SITES=	http://zipper.paco.net/~igor/oops/

MAINTAINER=	ozz@FreeBSD.org.ru

LIB_DEPENDS=	db2.0:${PORTSDIR}/databases/db

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sbindir=${PREFIX}/sbin \
		--sysconfdir=${PREFIX}/etc/oops \
		--localstatedir=/var/run \
		--libdir=${PREFIX}/libexec/oops \
		--enable-oops-user=oops

pre-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

.include <bsd.port.pre.mk>

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@ ${ECHO} "------------------------------------------------------------"
	@ ${ECHO} "Sample of configuration file placed at ${PREFIX}/etc/oops !"
	@ ${ECHO} "Copy oops.cfg.sample to oops.cfg, then run server..."
	@ ${ECHO} "------------------------------------------------------------"

	@if [ ! -f ${PREFIX}/etc/rc.d/oops.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/oops.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/oops.sh ${PREFIX}/etc/rc.d/oops.sh; \
	fi

.include <bsd.port.post.mk>
