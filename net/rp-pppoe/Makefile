# New ports collection makefile for:	popular pppd pppoe client
# Date created:		22 Mar 2001
# Whom:			Mario Sergio Fujikawa Ferreira <liouxFreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rp-pppoe
PORTVERSION=	2.8
CATEGORIES=	net
MASTER_SITES=	http://www.roaringpenguin.com/pppoe/

MAINTAINER=	ports@FreeBSD.org

BROKEN=	Does not work well with FreeBSD\'s pppd, yet.\
	Need help to be fixed

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_WRKSRC=	${WRKSRC}/src
BUILD_WRKSRC=	${WRKSRC}/src

MAN5=	pppoe.conf.5
MAN8=	adsl-connect.8 adsl-setup.8 adsl-start.8 adsl-status.8 \
	adsl-stop.8 pppoe-relay.8 pppoe-server.8 pppoe-sniff.8 \
	pppoe.8

CONFIG_FILES=	firewall-masq firewall-standalone pap-secrets \
		pppoe-server-options pppoe.conf
DOC_FILES=	CHANGES HOW-TO-CONNECT KERNEL-MODE-PPPOE LICENSE \
		PROBLEMS
SCRIPT_FILES=	adsl-connect adsl-init adsl-setup adsl-start \
		adsl-status adsl-stop

post-patch:
	@${PERL} -pi -ne "s!/etc/ppp!${PREFIX}/etc/ppp!g" ${WRKSRC}/man/*
	@${PERL} -pi -ne 's!/etc/ppp!\$$\(prefix)/etc/ppp!g' \
		${WRKSRC}/src/Makefile.in
.for file in adsl-connect adsl-init adsl-setup adsl-start
	@${PERL} -pi -ne 's!/etc/+ppp!\$$\{prefix}/etc/ppp!g' \
		${WRKSRC}/scripts/${file}.in
.endfor
	@${PERL} -pi -ne 's!pty!tty!g' ${WRKSRC}/scripts/adsl-connect.in
	@${PERL} -pi -ne 's!/var/lock/subsys/adsl!/var/tmp/rp_pppoe_adsl!g' \
		${WRKSRC}/scripts/adsl-init.in
.for file in adsl-status adsl-stop.in
	@${PERL} -pi -ne "s!/etc/ppp!${PREFIX}/etc/ppp!g" \
		${WRKSRC}/scripts/${file}
.endfor

do-install:
# Binaries
.for file in pppoe pppoe-server pppoe-sniff
	@${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${file} ${PREFIX}/sbin
.endfor
# Configurations
	@${MKDIR} ${PREFIX}/etc/ppp
.for file in ${CONFIG_FILES}
	@${INSTALL_DATA} ${WRKSRC}/configs/${file} \
		${PREFIX}/etc/ppp/${file}.sample
.endfor
.if !exists(${PREFIX}/etc/ppp/pppoe.conf)
	${INSTALL_SCRIPT} ${PREFIX}/etc/ppp/pppoe.conf.sample \
		${PREFIX}/etc/ppp/pppoe.conf
.endif
# Manual pages
	@${INSTALL_MAN} ${WRKSRC}/man/${MAN5} ${PREFIX}/man/man5
.for file in ${MAN8}
	@${INSTALL_MAN} ${WRKSRC}/man/${file} ${PREFIX}/man/man8
.endfor
# Scripts
.for file in ${SCRIPT_FILES}
	@${INSTALL_SCRIPT} ${WRKSRC}/scripts/${file} ${PREFIX}/sbin
.endfor
# Documentation
.ifndef (NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/${PORTNAME}
.endif /* NOPORTDOCS */

.include <bsd.port.mk>
