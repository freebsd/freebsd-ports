# New ports collection makefile for:	dtcp
# Date Created:		Sep 27 2002
# Whom:			Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dtcp
PORTVERSION=	20040611
#PORTREVISION=	0
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.imasy.or.jp/~ume/ipv6/ \
		http://home.jp.FreeBSD.org/~ume/ipv6/

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Dynamic Tunnel Configuration Protocol daemon and client

.if !defined(DTCP_CLIENT_ONLY)
RUN_DEPENDS=	qpopauth:${PORTSDIR}/mail/qpopper
.endif

USE_RC_SUBR=	yes
USE_RUBY=	yes
MAKE_ENV+=	RUBY=${RUBY}

MAN8=		dtcpauth.8 dtcpc.8 dtcps.8
MANCOMPRESSED=	yes

RC_SCRIPTS=	${PREFIX}/etc/rc.d/dtcpc.sh ${PREFIX}/etc/rc.d/dtcps.sh
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR} RUBY=${RUBY}

pre-everything::
.if !defined(DTCP_CLIENT_ONLY)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If you don't use DTCP server, you don't need qpopper."
	@${ECHO_MSG} "In that case, You may use DTCP_CLIENT_ONLY=yes to avoid building qpopper."
	@${ECHO_MSG} ""
.endif

pre-install:
	@for script in ${RC_SCRIPTS}; do \
		if [ -f $${script} ]; then \
			${ECHO_MSG} "Remove old $${script} before install."; \
			exit 1; \
		fi; \
	done

post-install:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/dtcpc.sh > ${PREFIX}/etc/rc.d/dtcpc.sh
	@${CHMOD} ${BINMODE} ${PREFIX}/etc/rc.d/dtcpc.sh
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/dtcps.sh > ${PREFIX}/etc/rc.d/dtcps.sh
	@${CHMOD} ${BINMODE} ${PREFIX}/etc/rc.d/dtcps.sh

.include <bsd.port.mk>
