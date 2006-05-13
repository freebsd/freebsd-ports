# New ports collection makefile for:	bugs
# Date created:		20 June 1998
# Whom:			Stephane Legrand
#
# $FreeBSD$
#

PORTNAME=	bugs
PORTVERSION=	4.1.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.encryptsolutions.com/english/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	stephane@freebsd-fr.org
COMMENT=	Great cryptography library and sample programs

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

USE_GMAKE=	yes

# No Manual page

post-extract:
	${FIND} ${WRKSRC} -type d -exec ${CHMOD} +x {} \;

post-configure:
	(cd ${WRKSRC}; ${MAKE} bsd);
	${REINPLACE_CMD} -e 's:^INSTALL_PATH = "/usr/local/bugs-.*":INSTALL_PATH = "${PREFIX}/${DISTNAME}":' ${WRKSRC}/Makefile;
	${REINPLACE_CMD} -e 's/^install: instchoice all/install: instchoice/' ${WRKSRC}/Makefile;
	# Comment the docs installation
	${REINPLACE_CMD} -e 's+\(@echo "Copying docs.*\)+# \1+' ${WRKSRC}/Makefile;
	${REINPLACE_CMD} -e 's+\(@cp -rf ./doc/.*\)+# \1+' ${WRKSRC}/Makefile;

post-build:
	${CP} ${WRKSRC}/lib/unix/*.a ${WRKSRC}/lib/

pre-install:
	(cd ${WRKSRC}; ${MAKE} test)

post-install:
.if !defined(NOPORTDOCS)
	${CP} -R ${WRKSRC}/doc ${PREFIX}/${DISTNAME}
.endif
	${CP} -R ${WRKSRC}/include ${PREFIX}/${DISTNAME}
	${STRIP_CMD} ${PREFIX}/${DISTNAME}/bchat \
		${PREFIX}/${DISTNAME}/bcrypt \
		${PREFIX}/${DISTNAME}/bhide \
		${PREFIX}/${DISTNAME}/bkey \
		${PREFIX}/${DISTNAME}/block \
		${PREFIX}/${DISTNAME}/blogin \
		${PREFIX}/${DISTNAME}/bmore \
		${PREFIX}/${DISTNAME}/bpass \
		${PREFIX}/${DISTNAME}/bpassdel \
		${PREFIX}/${DISTNAME}/bunlock \

.include <bsd.port.mk>
