PORTNAME=	pam_ssh_agent_auth
PORTVERSION=	0.10.4
PORTREVISION=	4
CATEGORIES=	security

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	PAM module which permits authentication via ssh-agent
WWW=		https://github.com/jbeverly/pam_ssh_agent_auth

# Note: if you need support for hardware token backed ecdsa-sk or
# ed25519-sk SSH keys, see devel/pam_rssh

USE_GITHUB=	yes
GH_ACCOUNT=	jbeverly
GH_TAGNAME=	099beb2
GH_TUPLE=	floodyberry:ed25519-donna:8757bd4:floodyberry_ed25519_donna/ed25519-donna

BROKEN_mips64=		fails to compile: ed25519-donna-portable.h:85:4: Need a uint128_t implementation!

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
