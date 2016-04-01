# Created by: kirk@strauser.com
# $FreeBSD$

PORTNAME=	bash-completion
PORTVERSION=	2.1
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	shells
MASTER_SITES=	http://bash-completion.alioth.debian.org/files/

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Programmable completion library for Bash

LICENSE=	GPLv2

RUN_DEPENDS=	bash:shells/bash

USE_AUTOTOOLS=	aclocal automake
GNU_CONFIGURE=	yes
USES=		gmake tar:bzip2

SUB_FILES=	pkg-message
SUB_LIST+=	RUNFILE=${DATADIR}/bash_completion.sh

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|FLAC|&\|flv\|FLV|;' ${WRKSRC}/bash_completion

post-configure:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g; \
		s|/etc/bash_completion|${PREFIX}&|g; \
		s|/usr\(/sbin/postconf\)|${PREFIX}\1|g; \
		s|/usr\(/lib/rpm/macros\)|${PREFIX}\1|g; \
		s|/usr/share\(/ssl/openssl.cnf\)|/etc\1|g; \
		s|/usr/ports|${PORTSDIR}|g; \
		s|/usr/lib\(/aspell\)|${PREFIX}/share\1|g; \
		s|/usr/share/info|&:${PREFIX}/info|g;' \
		${WRKSRC}/completions/*

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README doc/bash_completion.txt doc/bashrc doc/inputrc
		${INSTALL_DATA} ${WRKSRC}/$i ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
