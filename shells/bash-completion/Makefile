PORTNAME=	bash-completion
PORTVERSION=	2.17.0
PORTREVISION=	3
PORTEPOCH=	2
CATEGORIES=	shells
MASTER_SITES=	https://github.com/scop/bash-completion/releases/download/${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Programmable completion library for Bash
WWW=		https://github.com/scop/bash-completion

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	bash:shells/bash \
		${PYTHON_PKGNAMEPREFIX}pexpect>=4:misc/py-pexpect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=0,1:devel/py-pytest-xdist@${PY_FLAVOR}

USES=		autoreconf gmake python:test tar:xz
USE_PYTHON=	pytest

GNU_CONFIGURE=	yes
NO_ARCH=	yes
TEST_WRKSRC=	${WRKSRC}/test

SUB_FILES=	pkg-message
SUB_LIST=	RUNFILE=${DATADIR}/bash_completion.sh

PORTSCOUT=	limit:^[0-9\.]*$$

OPTIONS_DEFINE=	CMAKE_MODULES FREEBSD ZFS
OPTIONS_DEFAULT=CMAKE_MODULES FREEBSD ZFS
OPTIONS_SUB=	yes
CMAKE_MODULES_DESC=	Install bash-completion modules for cmake
FREEBSD_DESC=		Add FreeBSD-specific completion
ZFS_DESC=		Add OpenZFS completion

FREEBSD_RUN_DEPENDS=	bash-completion-freebsd>=0:shells/bash-completion-freebsd
ZFS_RUN_DEPENDS=	bash-completion-zfs>=0:shells/bash-completion-zfs

post-configure:
	@${REINPLACE_CMD} \
		-e 's|/etc/ssl/openssl.cnf|${PREFIX}& &|g' \
		-e 's|/usr/lib\(/aspell\)|${PREFIX}/share\1|g' \
		-e 's|/usr/local|${PREFIX}|g' \
		-e 's|/usr/ports|${PORTSDIR}|g' \
		-e 's|/usr\(/sbin/postconf\)|${PREFIX}\1|g' \
		-e 's|/usr/share/info|&:${PREFIX}/info|g' \
		-e 's|/var\(/lib/rpm/macros\)|${PREFIX}\1|g' \
			${WRKSRC}/completions/*

post-install:
	${RM} ${STAGEDIR}${DATADIR}/completions/interdiff
	${RM} ${STAGEDIR}${DATADIR}/completions/makepkg

.include <bsd.port.mk>
