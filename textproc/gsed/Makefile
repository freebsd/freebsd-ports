# New ports collection makefile for:	sed
# Date created:				12 October 2000
# Whom:					Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#

PORTNAME=	sed
PORTVERSION=	3.02
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR= sed

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes

# sed's configure seems to be buggy !
# CONFIGURE_ARGS=	--program-prefix=g

MAN1=		gsed.1

post-configure:
	@${PERL} -pi.fbsd -e 's/s,x,x,/s,^,g,/' \
		${WRKSRC}/Makefile \
		${WRKSRC}/doc/Makefile \
		${WRKSRC}/lib/Makefile \
		${WRKSRC}/sed/Makefile

post-install: share-examples
	@install-info ${PREFIX}/info/sed.info ${PREFIX}/info/dir

share-examples:
	@${MKDIR} ${PREFIX}/share/examples/gsed
	@${INSTALL_DATA} ${WRKSRC}/dc.sed ${PREFIX}/share/examples/gsed

.include <bsd.port.mk>
