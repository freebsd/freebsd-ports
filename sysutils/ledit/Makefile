PORTNAME=	ledit
PORTVERSION=	2.06
CATEGORIES=	sysutils

MAINTAINER=	k@stereochro.me
COMMENT=	Line editor to be used with interactive commands
WWW=		http://cristal.inria.fr/~ddr/ledit/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	camlp5r:devel/ocaml-camlp5 \
		${OCAMLFIND_DEPEND}

USES=		gmake
USE_OCAML=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	chetmurthy
GH_TAGNAME=	ledit-${PORTVERSION:S/./-/}

ALL_TARGET=	all ledit.opt
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS

do-configure:
	${REINPLACE_CMD} -e '/^INCLUDES=/s|-I +../camlp-streams|-I +site-lib/camlp-streams|' \
			-e '/^CAMLP5=/s|-I +../camlp-streams|-I +site-lib/camlp-streams|' \
			${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ledit.opt ${STAGEDIR}${PREFIX}/bin/ledit
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/CHANGES ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man1
	@${INSTALL_MAN} ${WRKSRC}/ledit.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
