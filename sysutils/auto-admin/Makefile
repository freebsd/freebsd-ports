# New ports collection makefile for:	auto-admin
# Date created:		2011-11-01
# Whom:			Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	auto-admin
PORTVERSION=	0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Tools for automating system management

NO_BUILD=	yes

MAN1=		auto-admin.1 \
		auto-amd-nfs-setup.1 \
		auto-amd-local-setup.1 \
		auto-append-line.1 \
		auto-ask.1 \
		auto-clean-ports.1 \
		auto-disable-service.1 \
		auto-enable-compat32.1 \
		auto-enable-passwdqc.1 \
		auto-enable-service.1 \
		auto-set-suspend-on-lid.1 \
		auto-fastest-mirror.1 \
		auto-install-packages.1 \
		auto-ipfw-gateway-setup.1 \
		auto-ldap-adduser.1 \
		auto-ldap-client-setup.1 \
		auto-package-installed.1 \
		auto-replace-file.1 \
		auto-service-enabled.1 \
		auto-update-port-framework.1 \
		auto-update-xorg.conf.1 \
		auto-xdm-toggle.1

do-install:
	${MKDIR} ${PREFIX}/sbin ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/* ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/Data/* ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/Doc/auto-admin.man \
		${MANPREFIX}/man/man1/auto-admin.1
	for name in ${WRKSRC}/Scripts/*; do \
		${INSTALL_MAN} ${WRKSRC}/Doc/auto-admin.man \
			${MANPREFIX}/man/man1/`basename $${name}`.1; \
	done

.include <bsd.port.mk>
