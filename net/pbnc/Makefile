# Ports collection makefile for:  pbnc
# Date created:	  03 Apr 2004
# Whom:		  hrs
#
# $FreeBSD$

PORTNAME=	pbnc
PORTVERSION=	1.0
CATEGORIES=	net
MASTER_SITES=	http://duncanthrax.net/pbnc/
DISTNAME=	pbnc

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Simple userspace TCP port bouncer

RUN_DEPENDS=	${SITE_PERL}/Net/Netmask.pm:${PORTSDIR}/net-mgmt/p5-Net-Netmask

NO_BUILD=	yes
PLIST=		${WRKSRC}/pkg-plist

CONFIGDIR=	etc
CONFIG_FILES=	pbnc.cfg
SCRIPTDIR=	bin
SCRIPT_FILES=	pbnc.pl
DOC_FILES=	pbnc.readme

pre-install:
	(${ECHO_CMD} "${CONFIGDIR}/${CONFIG_FILES}"; \
	${ECHO_CMD} "${SCRIPTDIR}/${SCRIPT_FILES}"; ) > ${PLIST}
.if !defined(NOPORTDOCS)
	(for F in ${DOC_FILES}; do \
			${ECHO_CMD} "${DOCSDIR:S,^${PREFIX}/,,}/$${F}"; \
		done;\
	${ECHO_CMD} "@dirrm ${DOCSDIR:S,^${PREFIX}/,,}" ) >> ${PLIST}
.endif

do-install:
	${INSTALL_SCRIPT} ${SCRIPT_FILES:S,^,${WRKSRC}/,} ${PREFIX}/${SCRIPTDIR}
	${INSTALL_DATA} ${CONFIG_FILES:S,^,${WRKSRC}/,} ${PREFIX}/${CONFIGDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
