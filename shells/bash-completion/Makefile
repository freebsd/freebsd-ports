# Created by: kirk@strauser.com
# $FreeBSD$

PORTNAME=	bash-completion
PORTVERSION=	2.4
PORTEPOCH=	1
CATEGORIES=	shells

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Programmable completion library for Bash

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	scop

USES=		autoreconf gmake pathfix
GNU_CONFIGURE=	yes
NO_ARCH=	yes

SUB_FILES=	pkg-message
SUB_LIST+=	RUNFILE=${DATADIR}/bash_completion.sh

OPTIONS_DEFINE=	CMAKE_MODULES DOCS
OPTIONS_DEFAULT=CMAKE_MODULES
CMAKE_MODULES_DESC=	Install bash-completion modules for cmake
OPTIONS_SUB=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		'/^profiledir =/s|(sysconfdir)/profile.d|(prefix)/share/bash-completion|; \
		s|\((datadir)/cmake\)|\1/Modules|' \
		${WRKSRC}/Makefile.am

post-configure:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g; \
		s|/usr\(/sbin/postconf\)|${PREFIX}\1|g; \
		s|/var\(/lib/rpm/macros\)|${PREFIX}\1|g; \
		s|\(/etc/ssl/openssl.cnf\)|${PREFIX}\1 \1|g; \
		s|/usr/ports|${PORTSDIR}|g; \
		s|/usr/lib\(/aspell\)|${PREFIX}/share\1|g; \
		s|/usr/share/info|&:${PREFIX}/info|g;' \
		${WRKSRC}/completions/*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in CHANGES README.md doc/bash_completion.txt doc/bashrc doc/inputrc
		${INSTALL_DATA} ${WRKSRC}/$i ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
