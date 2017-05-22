# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pam_ssh_agent_auth
PORTVERSION=	0.10.3
CATEGORIES=	security
MASTER_SITES=	SF/pamsshagentauth/${PORTNAME}/v${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PAM module which permits authentication via ssh-agent

BROKEN_powerpc64=	fails to build: ed25519-donna-portable.h: warning: ALIGN redefined

USES=		perl5 ssl tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_func_strnvis=no
CONFIGURE_ARGS=	--libexecdir=${LOCALBASE}/lib \
		--with-ssl-dir=${OPENSSLBASE}

PLIST_FILES=	lib/pam_ssh_agent_auth.so \
		man/man8/pam_ssh_agent_auth.8.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pam_ssh_agent_auth.so

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT:Mopenssl-devel}
BROKEN=		Does not build with openssl-devel
.endif

.include <bsd.port.post.mk>
