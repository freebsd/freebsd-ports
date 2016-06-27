# Created by: b.f. <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	alt-ergo
PORTVERSION=	0.95.2
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://alt-ergo.ocamlpro.com/http/alt-ergo-${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automatic solver of mathematical formulas for program verification

LICENSE=	CeCILL-C
LICENSE_NAME=	Ce[a] C[nrs] I[nria] L[ogiciel] L[ibre] C license, version 1
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	ocaml-zarith>1.2:math/ocaml-zarith \
		ocaml-ocamlgraph>1.8:math/ocaml-ocamlgraph
RUN_DEPENDS=	ocaml-ocamlgraph>1.8:math/ocaml-ocamlgraph

GNU_CONFIGURE=	yes
USES=		gmake
USE_OCAML=	yes
ALL_TARGET=	opt pack xpack META
INSTALL_TARGET=	install install-pack-opt install-pack-byte

OPTIONS_DEFINE=	GUI
OPTIONS_DEFAULT=GUI
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGUI}
BUILD_DEPENDS +=	lablgtk2:x11-toolkits/ocaml-lablgtk2
RUN_DEPENDS+=		lablgtk2:x11-toolkits/ocaml-lablgtk2
ALL_TARGET+=		gui
INSTALL_TARGET+=	install-gui
.endif

post-patch:
	@${REINPLACE_CMD} -e '\|^# installation|,\|^# documentation|{ \
		\|cp -f.*$$(BINDIR)|s|cp -f|${INSTALL_SCRIPT}|; \
		\|cp -f.*$$(MANDIR)|s|cp -f|${INSTALL_MAN}|; \
		\|cp -f.*$$(LIBDIR)|s|cp -f|${INSTALL_DATA}|; }' \
		-e 's|make -C|${MAKE_CMD} -C|' \
			${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -Ee 's@(\+|/)(lablgtk2)@\1site-lib/\2@' \
		${WRKSRC}/configure

.if ${PORT_OPTIONS:MGUI}
pre-configure:
	@(if [ ! -e ${LOCALBASE}/${OCAML_SITELIBDIR}/lablgtk2/lablgtksourceview2.cmxa ] ; then \
	${ECHO_MSG} "==> The WITH_GUI option for ${PKGNAME} requires" ; \
	${ECHO_MSG} "==> x11-toolkits/ocaml-lablgtk2 to be built" ; \
	${ECHO_MSG} "==> WITH_GTKSOURCEVIEW2" ; \
	exit 1; fi)
.endif

.include <bsd.port.mk>
