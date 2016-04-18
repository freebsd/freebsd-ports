# $FreeBSD$

PORTNAME=	poudriere
DISTVERSION=	3.1.12
PORTREVISION=	2
CATEGORIES=	ports-mgmt
MASTER_SITES=	LOCAL/bdrewery/${PORTNAME}/ \
		http://mirror.shatow.net/freebsd/${PORTNAME}/ \
		GH
MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Port build and test system

LICENSE=	BSD2CLAUSE

CONFLICTS_INSTALL=	poudriere-devel-[0-9]*

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd

GNU_CONFIGURE=	yes
ETCDIR=		${PREFIX}/etc/poudriere.d

OPTIONS_DEFINE=	ZSH QEMU EXAMPLES
OPTIONS_DEFAULT=ZSH
OPTIONS_SUB=	yes

QEMU_DESC=	Add qemu-user-static to compile ports for non-x86 architectures
QEMU_RUN_DEPENDS=	qemu-user-static>0:emulators/qemu-user-static

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions/
	${INSTALL_DATA} ${WRKSRC}/completions/zsh/_poudriere \
	    ${STAGEDIR}${PREFIX}/share/zsh/site-functions/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/MANIFESTS
	${INSTALL_DATA} ${FILESDIR}/MANIFESTS/* ${STAGEDIR}${PREFIX}/share/${PORTNAME}/MANIFESTS/

.include <bsd.port.mk>
