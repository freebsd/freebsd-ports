PORTNAME=	bash-completion
PORTVERSION=	2.16.0
PORTEPOCH=	2
CATEGORIES=	shells
MASTER_SITES=	https://github.com/scop/bash-completion/releases/download/${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Programmable completion library for Bash
WWW=		https://github.com/scop/bash-completion

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	runtest:misc/dejagnu \
		${LOCALBASE}/lib/tcllib/cmdline/cmdline.tcl:devel/tcllib

USES=		autoreconf gmake pathfix tar:xz

GNU_CONFIGURE=	yes
NO_ARCH=	yes

SUB_FILES=	pkg-message
SUB_LIST=	RUNFILE=${DATADIR}/bash_completion.sh

PORTSCOUT=	limit:^[0-9\.]*$$

OPTIONS_DEFINE=	CMAKE_MODULES FREEBSD ZFS
OPTIONS_SINGLE=	BASH
OPTIONS_SINGLE_BASH=	BASH_SHARED BASH_STATIC
OPTIONS_DEFAULT=BASH_SHARED CMAKE_MODULES FREEBSD ZFS
OPTIONS_SUB=	yes
BASH_SHARED_DESC=	Use shells/bash as backend
BASH_STATIC_DESC=	Use shells/bash-static as backend
CMAKE_MODULES_DESC=	Install bash-completion modules for cmake
FREEBSD_DESC=		Add FreeBSD-specific completion
ZFS_DESC=		Add OpenZFS completion

BASH_SHARED_RUN_DEPENDS=bash:shells/bash
BASH_STATIC_RUN_DEPENDS=bash:shells/bash-static
FREEBSD_RUN_DEPENDS=	bash-completion-freebsd>=0:shells/bash-completion-freebsd
ZFS_RUN_DEPENDS=	bash-completion-zfs>=0:shells/bash-completion-zfs

.include <bsd.port.options.mk>

.if ${ARCH} == riscv64
EXTRACT_CMD=	${SETENV} LC_ALL=en_US.UTF-8 /usr/bin/bsdtar
.endif

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
	${RM} ${STAGEDIR}${DATADIR}/completions/makepkg

do-test:
.for test in runCompletion runInstall runUnit
	-cd ${WRKSRC}/test && bash ${test}
.endfor

.include <bsd.port.mk>
