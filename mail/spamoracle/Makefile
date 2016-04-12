# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spamoracle
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://cristal.inria.fr/~xleroy/software/

MAINTAINER=	xride@FreeBSD.org
COMMENT=	procmail spam filter written in ML using Bayesian classification

BUILD_DEPENDS=	ocaml:lang/ocaml

PLIST_FILES=	bin/spamoracle
PLIST_FILES+=	man/man1/spamoracle.1.gz
PLIST_FILES+=	man/man5/spamoracle.conf.5.gz

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	Changes README
.endif

do-configure:
	@${REINPLACE_CMD} -E -e 's|^(CPP=)gcc[[:space:]]+-E|\1${CPP}|' \
		-e 's|^(MANDIR=).*$$|\1${STAGEDIR}${MANPREFIX}/man|' \
		-e 's|^(BINDIR=).*$$|\1${STAGEDIR}${PREFIX}/bin|' \
		${WRKSRC}/Makefile

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
