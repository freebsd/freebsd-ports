# Created by: Jaap Boender <jaapb@kerguelen.org>
# $FreeBSD$

PORTNAME=	eliom
PORTVERSION=	3.0.3
CATEGORIES=	www
MASTER_SITES=	http://ocsigen.org/download/

MAINTAINER=	jaapb@kerguelen.org
COMMENT=	Ocaml dynamic webpage generation library

LICENSE=	LGPL21_SSLEX
LICENSE_NAME=	Lesser GPL 2.1 with a special OpenSSL exception clause
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${PORTREQS}
RUN_DEPENDS=	${PORTREQS}

DOCSDIR=	${PREFIX}/share/doc/ocaml/${PORTNAME}
SA_DIR=		${PREFIX}/${OCAML_SITELIBDIR}

# As of 27 March 2014, USE_OCAML_LDCONFIG and USE_OCAMLFIND_PLIST compete
# for the same directores -- both add a removal step ot the TMPPLIST
# automatically.  The bsd.ocaml.mk file has to be fixed, then then former
# can be used again.  (alternatively we could provide a manually generated
# complete pkg-plist and keep using ocaml's ldconfig)

USES=			gmake
HAS_CONFIGURE=		yes
USE_OCAML=		yes
USE_OCAML_FINDLIB=	yes
USE_OCAMLFIND_PLIST=	yes
#USE_OCAML_LDCONFIG=	yes
CONFIGURE_ARGS=		--temproot ${STAGEDIR} \
			--prefix ${PREFIX} \
			--libdir ${PREFIX}/lib/ocaml/site-lib \
			--enable-natdynlink

PORTREQS=	ocaml-deriving-ocsigen>=0.3:${PORTSDIR}/devel/ocaml-deriving-ocsigen \
		js_of_ocaml>=1.3.2:${PORTSDIR}/lang/js_of_ocaml \
		ocsigen>=2.2:${PORTSDIR}/www/ocsigen \
		ocaml-tyxml>=2.2:${PORTSDIR}/textproc/ocaml-tyxml \
		${SA_DIR}/react/react.a:${PORTSDIR}/devel/ocaml-react \
		${SA_DIR}/ssl/ssl.a:${PORTSDIR}/security/ocaml-ssl \
		${SA_DIR}/calendar/calendarLib.a:${PORTSDIR}/devel/ocaml-calendar \
		${SA_DIR}/cryptokit/cryptokit.a:${PORTSDIR}/security/ocaml-cryptokit

do-configure:
	(cd ${WRKSRC} && ${SH} ./configure ${CONFIGURE_ARGS})

.include <bsd.port.mk>
