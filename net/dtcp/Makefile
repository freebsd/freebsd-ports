# New ports collection makefile for:	dtcp
# Date Created:		Sep 27 2002
# Whom:			Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dtcp
PORTVERSION=	20030101
#PORTREVISION=	0
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.imasy.or.jp/~ume/ipv6/

MAINTAINER=	ume@FreeBSD.org

.if !defined(DTCP_CLIENT_ONLY)
RUN_DEPENDS=	qpopauth:${PORTSDIR}/mail/qpopper
.endif

USE_RUBY=	yes
RUBY_SHEBANG_FILES=	${WRKSRC}/dtcpauth.rb ${WRKSRC}/dtcpc.rb \
			${WRKSRC}/dtcps.rb

WRKSRC=		${WRKDIR}/dtcp

MAN8=		dtcpauth.8 dtcpc.8 dtcps.8
MANCOMPRESSED=	yes

pre-everything:
.if !defined(DTCP_CLIENT_ONLY)
	@${ECHO} ""
	@${ECHO} "If you don't use DTCP server, you don't need qpopper."
	@${ECHO} "In that case, You may use DTCP_CLIENT_ONLY=yes to avoid building qpopper."
	@${ECHO} ""
.endif

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dtcpc.sh \
		${PREFIX}/etc/rc.d/dtcpc.sh.sample
	${INSTALL_SCRIPT} ${WRKSRC}/dtcps.sh \
		${PREFIX}/etc/rc.d/dtcps.sh.sample

.include <bsd.port.mk>
