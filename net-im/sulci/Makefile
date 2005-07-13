# New ports collection makefile for:	sulci
# Date created:				Fri Jul  8 13:12:34 MSD 2005
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	sulci
PORTVERSION=	20050708
CATEGORIES=	net
MASTER_SITES=	http://neva.vlink.ru/distfiles/

MAINTAINER=	dsh@vlink.ru
COMMENT=	A Jabber bot

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		${LOCALBASE}/lib/ocaml/cryptokit.cma:${PORTSDIR}/security/ocaml-cryptokit \
		${OCAML_SITELIBDIR}/ulex/ulexing.a:${PORTSDIR}/devel/ocaml-ulex \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib
LIB_DEPENDS=	sqlite.2:${PORTSDIR}/databases/sqlite2 \
		pcre.0:${PORTSDIR}/devel/pcre-utf8
RUN_DEPENDS=	${OCAML_SITELIBDIR}/netstring/netstring.a:${PORTSDIR}/www/ocaml-net \
		${OCAML_SITELIBDIR}/pcre/pcre.a:${PORTSDIR}/devel/ocaml-pcre
BUILD_DEPENDS+=	${RUN_DEPENDS}

OCAML_SITELIBDIR=	${LOCALBASE}/lib/ocaml/site-lib

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_RC_SUBR=	${PORTNAME}.sh

ALL_TARGET=	subdirs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}/${PORTNAME} ${PREFIX}/sbin

	${MKDIR} ${DATADIR}/lang
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/lang/*.htbl ${WRKSRC}/${PORTNAME}/lang/*.ml ${WRKSRC}/${PORTNAME}/lang/*.msg ${DATADIR}/lang
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/tlds.db ${DATADIR}

	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/${PORTNAME}.conf.example ${EXAMPLESDIR}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${FILESDIR}/cmdlist.ru.txt ${DOCSDIR}
.endif

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
