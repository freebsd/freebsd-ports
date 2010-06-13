# New ports collection makefile for:	popular pppd pppoe client
# Date created:		22 Mar 2001
# Whom:			Mario Sergio Fujikawa Ferreira <liouxFreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rp-pppoe
PORTVERSION=	3.10
CATEGORIES=	net
MASTER_SITES=	http://www.roaringpenguin.com/files/download/

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	The popular Roaring Penguin's PPPoE software

GNU_CONFIGURE=	yes
PATCH_WRKSRC=	${WRKSRC}/src
CONFIGURE_WRKSRC=	${WRKSRC}/src
BUILD_WRKSRC=	${WRKSRC}/src

MAKE_JOBS_SAFE=	yes

MAN5=	pppoe.conf.5
MAN8=	pppoe-connect.8 pppoe-setup.8 pppoe-start.8 pppoe-status.8 \
	pppoe-stop.8 pppoe-relay.8 pppoe-server.8 pppoe.8

CONFIG_FILES=	firewall-masq firewall-standalone pap-secrets \
		pppoe-server-options pppoe.conf
DOC_FILES=	CHANGES HOW-TO-CONNECT KERNEL-MODE-PPPOE LICENSE \
		PROBLEMS
SCRIPT_FILES=	pppoe-connect pppoe-init pppoe-setup pppoe-start \
		pppoe-status pppoe-stop
.ifndef (NOPORTDOCS)
PORTDOCS=	*
.endif

post-patch:
	@${REINPLACE_CMD} -e "s!/etc/ppp!${PREFIX}/etc/ppp!g" ${WRKSRC}/man/*
	@${REINPLACE_CMD} -e 's!/etc/ppp!$$(prefix)/etc/ppp!g' \
		${WRKSRC}/src/Makefile.in
.for file in pppoe-connect pppoe-init pppoe-setup pppoe-start
	@${REINPLACE_CMD} -e 's!/etc/+ppp!$${prefix}/etc/ppp!g' \
		${WRKSRC}/scripts/${file}.in
.endfor
	@${REINPLACE_CMD} -e 's!pty!tty!g' ${WRKSRC}/scripts/pppoe-connect.in
	@${REINPLACE_CMD} -e 's!/var/lock/subsys/adsl!/var/tmp/rp_pppoe_adsl!g' \
		${WRKSRC}/scripts/pppoe-init.in
.for f in pppoe-status pppoe-stop.in
	@${REINPLACE_CMD} -e "s!/etc/ppp!${PREFIX}/etc/ppp!g" \
		${WRKSRC}/scripts/${f}
.endfor

do-install:
# Binaries
.for f in pppoe pppoe-server pppoe-relay
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${f} ${PREFIX}/sbin
.endfor
# Configurations
	${MKDIR} ${PREFIX}/etc/ppp
.for f in ${CONFIG_FILES}
	${INSTALL_DATA} ${WRKSRC}/configs/${f} \
		${PREFIX}/etc/ppp/${f}.sample
.endfor
# Manual pages
	${MKDIR} ${MAN5PREFIX}/man/man5
.for f in ${MAN5}
	${INSTALL_MAN} ${WRKSRC}/man/${f} ${MAN5PREFIX}/man/man5
.endfor
	${MKDIR} ${MAN8PREFIX}/man/man8
.for f in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/man/${f} ${MAN8PREFIX}/man/man8
.endfor
# Scripts
.for f in ${SCRIPT_FILES}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/${f} ${PREFIX}/sbin
.endfor
# Startup scripts
.for f in 04pppoe-relay.sh.sample 04pppoe-server.sh.sample
	${INSTALL_SCRIPT} ${FILESDIR}/${f} ${PREFIX}/etc/rc.d/
.endfor

# Documentation
.ifndef (NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif # NOPORTDOCS

.include <bsd.port.mk>
