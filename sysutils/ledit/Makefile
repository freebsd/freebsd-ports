# Created by: Marwan Burelle <marwan.burelle@lri.fr>
# $FreeBSD$

PORTNAME=	ledit
PORTVERSION=	2.03
CATEGORIES=	sysutils
MASTER_SITES=	http://cristal.inria.fr/~ddr/ledit/distrib/src/ \
		http://pauillac.inria.fr/~ddr/ledit/distrib/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Line editor to be used with interactive commands

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	camlp5r:${PORTSDIR}/devel/ocaml-camlp5

USES=		gmake
USE_OCAML=	yes

ALL_TARGET=	all ledit.opt

PLIST_FILES=	bin/ledit
MAKE_JOBS_UNSAFE=	yes

MAN1=		ledit.1
PORTDOCS=	CHANGES LICENSE README
OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
do-configure:
	${REINPLACE_CMD} -e '/^BINDIR=/s;/usr/local;${PREFIX};' \
			-e '/^LIBDIR=/s;/usr/local;${PREFIX};' \
			-e '/^MANDIR=/s;/usr/local;${PREFIX};' \
			${WRKSRC}/Makefile

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
