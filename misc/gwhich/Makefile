# Created by: Jeremy Shaffner <jeremy@external.org>
# $FreeBSD$

PORTNAME=	gwhich
PORTVERSION=	2.21
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	GNU/which
DISTNAME=	which-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	GNU Which - Everything you never wanted in a which

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g

INFO=		which
PORTEXAMPLES=	EXAMPLES
PLIST_FILES=	bin/gwhich man/man1/gwhich.1.gz

OPTIONS_DEFINE=	EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/EXAMPLES ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
