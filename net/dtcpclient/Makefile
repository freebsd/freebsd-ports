# New ports collection makefile for:	dtcpclient
# Date Created:		Feb 27 2003
# Whom:			Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dtcpclient
PORTVERSION=	20040410
#PORTREVISION=	0
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.imasy.or.jp/~ume/ipv6/ \
		http://home.jp.FreeBSD.org/~ume/ipv6/

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Dynamic Tunnel Configuration Protocol client

USE_RC_SUBR=	YES

MAN8=		dtcpclient.8
MANCOMPRESSED=	yes

RC_SCRIPT=	${PREFIX}/etc/rc.d/dtcpclient.sh
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

pre-install:
	@if [ -f ${RC_SCRIPT} ]; then \
		echo "Remove old ${RC_SCRIPT} before install."; \
		exit 1; \
	fi

post-install:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/dtcpclient.sh > ${WRKDIR}/dtcpclient.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/dtcpclient.sh ${RC_SCRIPT}

.include <bsd.port.mk>
