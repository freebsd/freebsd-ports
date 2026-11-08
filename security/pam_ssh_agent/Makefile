PORTNAME=	pam-ssh-agent
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	security

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	PAM module for authenticating using ssh-agent
WWW=		https://github.com/nresare/pam-ssh-agent

LICENSE=	MIT APACHE20
LICENSE_COMB=	dual
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE

USES=		cargo ssl
USE_GITHUB=	yes

GH_ACCOUNT=	nresare

PLIST_FILES=	lib/pam_ssh_agent.so

do-install:
.ifdef WITH_DEBUG
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/debug/libpam_ssh_agent.so ${STAGEDIR}${PREFIX}/lib/pam_ssh_agent.so
.else
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/release/libpam_ssh_agent.so ${STAGEDIR}${PREFIX}/lib/pam_ssh_agent.so
.endif

.include <bsd.port.mk>
