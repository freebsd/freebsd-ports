# Created by: Marwan Burelle <marwan.burelle@lri.fr>
# $FreeBSD$

PORTNAME=	ledit
PORTVERSION=	2.04
CATEGORIES=	sysutils
MASTER_SITES=	http://cristal.inria.fr/%SUBDIR%/ \
		http://pauillac.inria.fr/%SUBDIR%/
MASTER_SITE_SUBDIR=	~ddr/${PORTNAME}/distrib/src

MAINTAINER=	k@stereochro.me
COMMENT=	Line editor to be used with interactive commands

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	camlp5r:devel/ocaml-camlp5

USES=		gmake tar:tgz
USE_OCAML=	yes

ALL_TARGET=	all ledit.opt
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS

do-configure:
	${REINPLACE_CMD} -e '/^BINDIR=/s|/usr/local|${STAGEDIR}${PREFIX}|' \
			-e '/^LIBDIR=/s|/usr/local|${STAGEDIR}${PREFIX}|' \
			-e '/^MANDIR=/s|/usr/local|${STAGEDIR}${PREFIX}|' \
			${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ledit
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
