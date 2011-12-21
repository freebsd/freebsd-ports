# New ports collection makefile for:	ng_mikrotik_eoip
# Date created:				19 Dec 2011
# Whom:					Maxim Ignatenko
#
# $FreeBSD$
#

PORTNAME=	ng_mikrotik_eoip
PORTVERSION=	1.0
CATEGORIES=	net kld
MASTER_SITES=	http://projects.ukrweb.net/files/ \
		http://imax.in.ua/files/

MAINTAINER=	gelraen.ua@gmail.com
COMMENT=	Netgraph node for Mikrotik EoIP tunneling

LICENSE=	BSD

OPTIONS=	PTABLE	"Use O(1) lookup for tunnel hooks"	OFF
# This option enables usage of static pointer table to find needed decimal-named hook,
# which increases memory usage for each node by 65536*sizeof(hook_p). You probably want
# this option if you have many tunnels with single remote IP.

KMODDIR?=	/boot/modules
PLIST_SUB+=	KMODDIR=${KMODDIR} \
		PORTNAME=${PORTNAME}

.if !exists(${SRC_BASE}/sys/sys/module.h)
IGNORE=		requires kernel source files
.endif

.include <bsd.port.options.mk>

.if defined(WITH_PTABLE)
MAKE_ARGS+=	NO_LINEAR_HOOK_LOOKUP=1
.endif

do-install:
	@${INSTALL_KLD} ${WRKSRC}/${PORTNAME}.ko ${KMODDIR}

.include <bsd.port.mk>
