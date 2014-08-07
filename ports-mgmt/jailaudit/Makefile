# Created by: Philipp Wuensche <cryx-ports@h3q.com>
# $FreeBSD$

PORTNAME=	jailaudit
PORTVERSION=	1.5.1
PORTREVISION=	1
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://outpost.h3q.com/software/jailaudit/

MAINTAINER=	cryx-ports@h3q.com
COMMENT=	Script to generate portaudit reports for jails

LICENSE=	Beerware
LICENSE_NAME=	Beerware
LICENSE_TEXT=	"THE BEER-WARE LICENCE": Philipp Wuensche <cryx-ports@h3q.com> \
		wrote this software. As long as you retain this notice you can \
		do whatever you want with this stuff. If we meet some day, and \
		you think this stuff is worth it, you can buy me a beer in return.
LICENSE_PERMS=	auto-accept

USES=	tar:bzip2

PERIODICDIR?=	${PREFIX}/etc/periodic
REPORTDIR?=	${PREFIX}/jailaudit/reports
XTMPDIR?=	${PREFIX}/jailaudit/tmp

PLIST_SUB+=	PERIODICDIR="${PERIODICDIR:S,^${PREFIX}/,,}" \
		REPORTDIR="${REPORTDIR:S,^${PREFIX}/,,}" \
		XTMPDIR="${XTMPDIR:S,^${PREFIX}/,,}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
RUN_DEPENDS=	${LOCALBASE}/sbin/portaudit:${PORTSDIR}/ports-mgmt/portaudit
.endif

pre-install:
	${MKDIR} ${STAGEDIR}${PERIODICDIR}/security

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/jailaudit ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/jailaudit.conf.sample ${STAGEDIR}${PREFIX}/etc
	${INSTALL_SCRIPT} ${WRKSRC}/410.jailaudit ${STAGEDIR}${PERIODICDIR}/security

post-install:
	${MKDIR} ${STAGEDIR}${REPORTDIR}
	${MKDIR} ${STAGEDIR}${XTMPDIR}

.include <bsd.port.post.mk>
