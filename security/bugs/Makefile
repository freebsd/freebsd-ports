# New ports collection makefile for:	bugs
# Date created:		20 June 1998
# Whom:			Stephane Legrand
#
# $FreeBSD$
#

PORTNAME=		bugs
PORTVERSION=		2.0.1
CATEGORIES=		security
MASTER_SITES=		http://www.asi.fr/~martinez/crypto/ \
			${MASTER_SITE_SUNSITE}
EXTRACT_SUFX=		.tgz

MAINTAINER=		stephane.legrand@bigfoot.com

USE_GMAKE=		yes

# No Manual page

# Cryptography = be extra careful...
NO_CDROM=	may contain export-restricted material
NO_PACKAGE=	may contain export-restricted material
RESTRICTED=	Cryptography

post-configure:
	(cd ${WRKSRC}; ${MAKE} bsd)
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.pre_sed
	${SED} -e 's:^INSTALL_PATH = "/usr/local/bugs-.*":INSTALL_PATH = "${PREFIX}/${DISTNAME}":' \
		-e 's/^install: instchoice all/install: instchoice/' \
		< ${WRKSRC}/Makefile.pre_sed > ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${CP} -R ${WRKSRC}/doc ${PREFIX}/${DISTNAME}
.endif
	${CP} -R ${WRKSRC}/include ${PREFIX}/${DISTNAME}
	strip ${PREFIX}/${DISTNAME}/bcrypt \
		${PREFIX}/${DISTNAME}/bhide \
		${PREFIX}/${DISTNAME}/bkey \
		${PREFIX}/${DISTNAME}/blogin \
		${PREFIX}/${DISTNAME}/bpass \
		${PREFIX}/${DISTNAME}/bpassdel \

.include <bsd.port.mk>
