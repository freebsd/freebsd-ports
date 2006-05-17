# New ports collection makefile for:	sulci
# Date created:				Fri Jul  8 13:12:34 MSD 2005
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	sulci
PORTVERSION=	0.5.a.20060221
PORTEPOCH=	1
CATEGORIES=	net-im
MASTER_SITES=	http://www.jabber.ru/files/sulci/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.a./-alpha-/}

MAINTAINER=	dsh@vlink.ru
COMMENT=	A Jabber bot

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		${LOCALBASE}/lib/ocaml/cryptokit.cma:${PORTSDIR}/security/ocaml-cryptokit \
		${OCAML_SITELIBDIR}/ulex/ulexing.a:${PORTSDIR}/devel/ocaml-ulex \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib \
		${OCAML_SITELIBDIR}/netstring/netstring.a:${PORTSDIR}/www/ocaml-net \
		${OCAML_SITELIBDIR}/netclient/netclient.a:${PORTSDIR}/net/ocaml-netclient \
		${OCAML_SITELIBDIR}/pcre/pcre.a:${PORTSDIR}/devel/ocaml-pcre
LIB_DEPENDS=	sqlite.2:${PORTSDIR}/databases/sqlite2 \
		pcre.0:${PORTSDIR}/devel/pcre-utf8
RUN_DEPENDS=	${OCAML_SITELIBDIR}/netstring/netstring.a:${PORTSDIR}/www/ocaml-net \
		mueller:${PORTSDIR}/russian/mueller-dic

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_RC_SUBR=	${PORTNAME}.sh

ALL_TARGET=	subdirs
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

OCAML_SITELIBDIR=	${LOCALBASE}/lib/ocaml/site-lib

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		does not build on ${ARCH}, included getopt.cmxa and ${LOCALBASE}/lib/ocaml/stdlib.cmxa conflict
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}/${PORTNAME} ${PREFIX}/sbin

	${MKDIR} ${PREFIX}/libexec/${PORTNAME}
.for i in lang/langcompile tlds/createtlds utils/wtf/wtf_convert
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}/${i} ${PREFIX}/libexec/${PORTNAME}
.endfor

	${MKDIR} ${DATADIR}/lang
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/lang/*.htbl ${WRKSRC}/${PORTNAME}/lang/*.msg ${DATADIR}/lang

.for i in tlds.db tlds.txt
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/tlds/${i} ${DATADIR}
.endfor

	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/${PORTNAME}.conf.example ${EXAMPLESDIR}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}

.  for i in COPYING
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.  endfor

.  for i in cmdlist.en.txt cmdlist.ru.txt
	${INSTALL_DATA} ${WRKSRC}/docs/sulci/${i} ${DOCSDIR}
.  endfor
.endif

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
