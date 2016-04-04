# Created by: ijliao
# $FreeBSD$

PORTNAME=	patchutils
PORTVERSION=	0.3.4
CATEGORIES=	misc
MASTER_SITES=	http://cyberelk.net/tim/data/patchutils/stable/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Small collection of programs that operate on patch files

RUN_DEPENDS=	bash:shells/bash

USES=		perl5 shebangfix tar:xz
USE_PERL5=	run build patch
GNU_CONFIGURE=	yes
SHEBANG_FILES=	scripts/*

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${STAGEDIR}/${MANPREFIX}/man/man1

.include <bsd.port.mk>
