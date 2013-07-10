# Created by: Stephane Legrand
# $FreeBSD$

PORTNAME=	bugs
PORTVERSION=	4.1.1
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SUNSITE/apps/crypto
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Great cryptography library and sample programs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake

MAKE_JOBS_UNSAFE=	yes

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

DOCSDIR=	${PREFIX}/${DISTNAME}/doc

post-configure:
	(cd ${WRKSRC}; ${MAKE} bsd);
	${REINPLACE_CMD} -e 's:^INSTALL_PATH = "/usr/local/bugs-.*":INSTALL_PATH = "${PREFIX}/${DISTNAME}":' ${WRKSRC}/Makefile;
	${REINPLACE_CMD} -e 's/^install: instchoice all/install: instchoice/' ${WRKSRC}/Makefile;
	# Comment the docs installation
	${REINPLACE_CMD} -e 's+\(@echo "Copying docs.*\)+# \1+' ${WRKSRC}/Makefile;
	${REINPLACE_CMD} -e 's+\(@cp -rf ./doc/.*\)+# \1+' ${WRKSRC}/Makefile;

post-build:
	@${LN} -sf ${WRKSRC}/lib/unix/*.a ${WRKSRC}/lib/

pre-install:
	(cd ${WRKSRC}; ${MAKE} test)

post-install:
	@${MKDIR} ${PREFIX}/${DISTNAME}/include
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${PREFIX}/${DISTNAME}/include
.for file in bchat bcrypt bhide bkey block blogin bmore bpass bpassdel bunlock
	@${STRIP_CMD} ${PREFIX}/${DISTNAME}/${file}
.endfor
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif

.include <bsd.port.mk>
