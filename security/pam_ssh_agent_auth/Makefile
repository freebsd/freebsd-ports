PORTNAME=	pam_ssh_agent_auth
PORTVERSION=	0.10.4
PORTREVISION=	6
CATEGORIES=	security

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	PAM module which permits authentication via ssh-agent
WWW=		https://github.com/jbeverly/pam_ssh_agent_auth

# Note: This port is abandonware: there have been no updates to the
# code in the main GitHub repository for 8+ years, and compilation
# against a modern OpenSSL implementation depends on patches from a
# 3rd party that have not been added to a release version in 6+ years.
# Users are advised to consider the alternatives of security/pam_rssh
# or security/pam_ssh_agent which provide almost identical
# functionality, but are actively maintained.

DEPRECATED=	Abandonware.  Consider security/pam_rssh or securit/pam_ssh_agent instead.
EXPIRATION_DATE=	2026-12-31

USE_GITHUB=	yes
GH_ACCOUNT=	jbeverly
GH_TAGNAME=	099beb2
GH_TUPLE=	floodyberry:ed25519-donna:8757bd4:floodyberry_ed25519_donna/ed25519-donna

USES=		perl5 ssl tar:bzip2
USE_PERL5=	build

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ENV=	ac_cv_func_strnvis=no PERL=/usr/bin/false
CONFIGURE_ARGS=	--libexecdir=${LOCALBASE}/lib \
		--with-ssl-dir=${OPENSSLBASE} \
		--without-openssl-header-check

PLIST_FILES=	lib/pam_ssh_agent_auth.so \
		share/man/man8/pam_ssh_agent_auth.8.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pam_ssh_agent_auth.so

.include <bsd.port.mk>
