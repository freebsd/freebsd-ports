# $FreeBSD$

PORTNAME=	poudriere
DISTVERSION=	3.1.99.20160531
PORTREVISION=	1
CATEGORIES=	ports-mgmt
MASTER_SITES=	LOCAL/bdrewery/${PORTNAME}/ \
		http://mirror.shatow.net/freebsd/${PORTNAME}/ \
		GH
PKGNAMESUFFIX=	-devel

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Port build and test system

LICENSE=	BSD2CLAUSE

CONFLICTS_INSTALL=	poudriere-[0-9]*

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd
GH_TAGNAME=	3.0-1663-gf6c1bad
#DISTNAME=	${GH_ACCOUNT}-${GH_PROJECT}-${GH_TAGNAME}

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

.include <bsd.port.mk>
