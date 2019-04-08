# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	biblical-curse
PORTVERSION=	0.02
CATEGORIES=	misc
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fake biblical curse generator

USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	biblical-curse
NO_BUILD=	yes

SRC=		${.CURDIR}/src

do-extract:
	@${CP} -R ${SRC}/ ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/biblical-curse ${STAGEDIR}${PREFIX}/bin/biblical-curse

.include <bsd.port.mk>
