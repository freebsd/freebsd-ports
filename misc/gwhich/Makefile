# New ports collection makefile for:	gwhich
# Date created:		20 September 2000
# Whom:			Jeremy Shaffner <jeremy@external.org>
#
# $FreeBSD$
#

PORTNAME=	gwhich
PORTVERSION=	2.16
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.cse.cuhk.edu.hk/pub/gnu/gnu/which/ \
		http://voodoo.bawue.com/download/
DISTNAME=	which-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Which - Everything you never wanted in a which

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g

MAN1=		gwhich.1
INFO=		which

EXAMPLESDIR_REL=	${EXAMPLESDIR:S,^${PREFIX}/,,}
PLIST_FILES=	bin/gwhich \
		${EXAMPLESDIR_REL}/EXAMPLES
PLIST_DIRS=	${EXAMPLESDIR_REL}

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/EXAMPLES ${EXAMPLESDIR}

.include <bsd.port.mk>
