# New ports collection makefile for:	ipfilter2dshield
# Date created:		2004-06-18
# Whom:			Joe Barbish <fbsd_user@a1poweruser.com>
#
# $FreeBSD$
#

PORTNAME=	ipfilter2dshield
PORTVERSION=	1.0
CATEGORIES=	security
MASTER_SITES=	http://www.dshield.org/clients/
DISTNAME=	dshield-freebsd.pl
EXTRACT_SUFX=	.txt

MAINTAINER=	fbsd_user@a1poweruser.com
COMMENT=	Official DShield client for ipfilter firewall logs

RUN_DEPENDS=	${SITE_PERL}/Net/Netmask.pm:${PORTSDIR}/net-mgmt/p5-Net-Netmask

USE_PERL5=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 490000
IGNORE=		"Not supported on releases prior to 4.9"
.endif

do-extract:
	[ -d ${WRKDIR} ] || ${MKDIR} ${WRKDIR}
	${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}/${DISTNAME}

do-build:

pre-install:
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=g" \
		-e "s=%%DISTNAME%%=${DISTNAME}=g" \
		pkg-message > ${PKGMESSAGE}
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=g" \
		-e "s=%%PORTNAME%%=${PORTNAME}=g" \
		-e "s=%%DISTNAME%%=${DISTNAME}=g" \
		pkg-deinstall > ${PKGDEINSTALL}

do-install:
	[ -d ${PREFIX}/etc/${PORTNAME} ] || ${MKDIR} ${PREFIX}/etc/${PORTNAME}
	${INSTALL} -o root -g wheel -m 644 ${WRKDIR}/${DISTNAME} \
		${PREFIX}/etc/${PORTNAME}/${DISTNAME}.dist
	${INSTALL} -o root -g wheel -m 760 ${WRKDIR}/${DISTNAME} ${PREFIX}/sbin

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
