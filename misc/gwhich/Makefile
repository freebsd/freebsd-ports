# Created by: Jeremy Shaffner <jeremy@external.org>
# $FreeBSD$

PORTNAME=	gwhich
PORTVERSION=	2.20
CATEGORIES=	misc
MASTER_SITES=	GNU/which \
		http://www.xs4all.nl/~carlo17/which/
DISTNAME=	which-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Which - Everything you never wanted in a which

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g

MAN1=		gwhich.1
INFO=		which
PORTEXAMPLES=	EXAMPLES
PLIST_FILES=	bin/gwhich

NO_STAGE=	yes
post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/EXAMPLES ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
