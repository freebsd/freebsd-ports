# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pam_ssh_agent_auth
PORTVERSION=	0.10.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/pamsshagentauth/${PORTNAME}/v${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PAM module which permits authentication via ssh-agent

BROKEN_mips64=		fails to compile: ed25519-donna-portable.h:85:4: Need a uint128_t implementation!
BROKEN_powerpc64=	fails to compile: ed25519-donna-portable.h: warning: ALIGN redefined

USES=		perl5 ssl tar:bzip2
USE_PERL5=	build

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_func_strnvis=no PERL=/usr/bin/false
CONFIGURE_ARGS=	--libexecdir=${LOCALBASE}/lib \
		--with-ssl-dir=${OPENSSLBASE} \
		--without-openssl-header-check

PLIST_FILES=	lib/pam_ssh_agent_auth.so \
		man/man8/pam_ssh_agent_auth.8.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pam_ssh_agent_auth.so

.include <bsd.port.mk>
