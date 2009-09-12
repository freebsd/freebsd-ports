# New ports collection makefile for:	cnupm
# Date created:				29 October 2003
# Whom:					Dennis S.Davidoff <null@1system.ru>
#
# $FreeBSD$
#

PORTNAME=	cnupm
PORTVERSION=	3.12
CATEGORIES=	net ipv6
MASTER_SITES=	http://pdp-11.org.ru/~form/cnupm/files/ \
		ftp://cvs.1system.ru/pub/local/src/cnupm/

MAINTAINER=	null@1system.ru
COMMENT=	The BPF Traffic Collector (IPv4/IPv6)

USE_RC_SUBR=	cnupm.sh
MAN8=		cnupm.8 cnupmstat.8
MANCOMPRESSED=	yes

CNUPM_OWN?=	cnupm
CNUPM_GRP?=	cnupm

PW=		/usr/sbin/pw

PLIST_SUB+=	CNUPM_OWN="${CNUPM_OWN}" CNUPM_GRP="${CNUPM_GRP}"

PORTDOCS=	README

post-install:
	${PW} groupshow ${CNUPM_GRP} 2>/dev/null || ${PW} groupadd \
		-n ${CNUPM_GRP}
	${PW} usershow ${CNUPM_OWN} 2>/dev/null || ${PW} useradd \
		-n ${CNUPM_OWN} -c 'Cnupm traffic collector' \
		-g ${CNUPM_GRP} -s /sbin/nologin
	${INSTALL} -o ${CNUPM_OWN} -g ${CNUPM_GRP} -m 750 -d ${PREFIX}/var/cnupm
	${PW} usermod -n ${CNUPM_OWN} -d ${PREFIX}/var/cnupm
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
