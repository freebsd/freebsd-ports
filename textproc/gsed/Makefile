# New ports collection makefile for:	sed
# Date created:				12 October 2000
# Whom:					Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#

PORTNAME=	gsed
PORTVERSION=	3.02
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	sed
DISTNAME=	sed-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes

# sed's configure seems to be buggy !
# CONFIGURE_ARGS=	--program-prefix=g

MAN1=		gsed.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sed/sed ${PREFIX}/bin/gsed
	${INSTALL_MAN} ${WRKSRC}/doc/sed.1 ${PREFIX}/man/man1/gsed.1
	${INSTALL_DATA} ${WRKSRC}/doc/sed.info ${PREFIX}/info
	@install-info ${PREFIX}/info/sed.info ${PREFIX}/info/dir
	@${MKDIR} ${PREFIX}/share/examples/gsed
	${INSTALL_DATA} ${WRKSRC}/dc.sed ${PREFIX}/share/examples/gsed

.include <bsd.port.mk>
