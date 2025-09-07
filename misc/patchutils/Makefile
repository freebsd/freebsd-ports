PORTNAME=	patchutils
PORTVERSION=	0.4.3
CATEGORIES=	misc
MASTER_SITES=	http://cyberelk.net/tim/data/patchutils/stable/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Small collection of programs that operate on patch files
WWW=		http://cyberelk.net/tim/software/patchutils/ \
		https://github.com/twaugh/patchutils

LICENSE=	GPLv2+

RUN_DEPENDS=	bash:shells/bash

USES=		gmake perl5 python:run shebangfix tar:xz

GNU_CONFIGURE=	yes

SHEBANG_FILES=	patchview/gitdiff scripts/*.in

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=	xmlto>=0:textproc/xmlto

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/svndiff ${STAGEDIR}${PREFIX}/bin/svndiff.patchutils

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
