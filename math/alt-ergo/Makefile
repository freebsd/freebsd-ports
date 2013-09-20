# Created by: b.f. <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	alt-ergo
PORTVERSION=	0.94
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://alt-ergo.lri.fr/http/alt-ergo-${PORTVERSION}/ LOCAL/bf

MAINTAINER=	bf@FreeBSD.org
COMMENT=	An automatic theorem prover dedicated to program verification

LICENSE=	CeCILL-C
LICENSE_NAME=	Ce[a] C[nrs] I[nria] L[ogiciel] L[ibre] C license, version 1
LICENSE_FILE=	${WRKSRC}/CeCILL-C
LICENSE_PERMS=	auto-accept

BUILD_DEPENDS=	${LOCALBASE}/lib/ocaml/ocamlgraph/graph.a:${PORTSDIR}/math/ocaml-ocamlgraph
RUN_DEPENDS=	${LOCALBASE}/lib/ocaml/ocamlgraph/graph.a:${PORTSDIR}/math/ocaml-ocamlgraph

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_OCAML=	yes

MAN1=	alt-ergo.1

OPTIONS_DEFINE=		GUI
OPTIONS_DEFAULT=	GUI

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGUI}
BUILD_DEPENDS +=	lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2
RUN_DEPENDS+=		lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2
ALL_TARGET=	all gui
INSTALL_TARGET =	install install-gui
PLIST_SUB+=	GUI=""
.else
PLIST_SUB+=	GUI="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '\|^# installation|,\|^# documentation|{ \
		\|cp -f.*$$(BINDIR)|s|cp -f|${INSTALL_SCRIPT}|; \
		\|cp -f.*$$(MANDIR)|s|cp -f|${INSTALL_MAN}|; \
		\|cp -f.*$$(LIBDIR)|s|cp -f|${INSTALL_DATA}|; \
		\|/usr/share/gtksourceview-2.0|s|/usr|${PREFIX}|; }' \
		-e 's|make -C|${GMAKE} -C|' \
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

pre-install:
	@${MKDIR} ${PREFIX}/share/gtksourceview-2.0/language-specs

.endif
.include <bsd.port.mk>
