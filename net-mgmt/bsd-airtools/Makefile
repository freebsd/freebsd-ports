# New ports collection makefile for:    bsd-airtools
# Date created:		2002/07/06
# Whom:			Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bsd-airtools
PORTVERSION=	0.3
CATEGORIES=	net-mgmt
MASTER_SITES=	http://people.FreeBSD.org/~seanc/ports/bsd-airtools/
DISTNAME=	${PORTNAME}-v${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	BSD Wireless Scanning Tools

CONF_AIRTOOLS=	dstumbler
MAKE_AIRTOOLS=	dweputils/dwepcrack dweputils/dwepdump \
		dweputils/dwepkeygen prism2ctl prism2dump
INST_AIRTOOLS=	${CONF_AIRTOOLS} ${MAKE_AIRTOOLS}

WRKSRC=		${WRKDIR}/${PORTNAME}

.if !exists(/usr/include/dev/wi/if_wavelan_ieee.h)
BROKEN=	You need to upgrade
.endif

do-build:
.for TOOL in ${CONF_AIRTOOLS}
	@cd ${WRKSRC}/${TOOL}; ${SH} ${CONFIGURE_SCRIPT}; ${MAKE}
.endfor
.for TOOL in ${MAKE_AIRTOOLS}
	@cd ${WRKSRC}/${TOOL}; ${MAKE}
.endfor

do-install:
	${MKDIR} ${DOCSDIR}
.for TOOL in ${INST_AIRTOOLS}
	@cd ${WRKSRC}/${TOOL}; ${MAKE} ${INSTALL_TARGET}
	${INSTALL_DATA} ${WRKSRC}/${TOOL}/README \
		${DOCSDIR}/README.`${BASENAME} ${TOOL}`
.endfor

.include <bsd.port.mk>
