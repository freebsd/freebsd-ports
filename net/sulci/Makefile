# New ports collection makefile for:	sulci
# Date created:				Fri Jul  8 13:12:34 MSD 2005
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	sulci
PORTVERSION=	0.5.a.20050723
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	http://neva.vlink.ru/distfiles/

MAINTAINER=	dsh@vlink.ru
COMMENT=	A Jabber bot

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		${LOCALBASE}/lib/ocaml/cryptokit.cma:${PORTSDIR}/security/ocaml-cryptokit \
		${OCAML_SITELIBDIR}/ulex/ulexing.a:${PORTSDIR}/devel/ocaml-ulex \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib \
		${OCAML_SITELIBDIR}/netstring/netstring.a:${PORTSDIR}/www/ocaml-net \
		${OCAML_SITELIBDIR}/pcre/pcre.a:${PORTSDIR}/devel/ocaml-pcre
LIB_DEPENDS=	sqlite.2:${PORTSDIR}/databases/sqlite2 \
		pcre.0:${PORTSDIR}/devel/pcre-utf8
RUN_DEPENDS=	${OCAML_SITELIBDIR}/netstring/netstring.a:${PORTSDIR}/www/ocaml-net \
		${OCAML_SITELIBDIR}/pcre/pcre.a:${PORTSDIR}/devel/ocaml-pcre \
		mueller:${PORTSDIR}/russian/mueller-dic

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

.  for i in COPYING ChangeLog
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.  endfor

.  for i in cmdlist.en.txt cmdlist.ru.txt
	${INSTALL_DATA} ${WRKSRC}/doc/sulci/${i} ${DOCSDIR}
.  endfor
.endif

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
