# Created by: b.f. <bf@FreeBSD.org>

PORTNAME=	alt-ergo
PORTVERSION=	0.95.2
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	http://alt-ergo.ocamlpro.com/http/alt-ergo-${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automatic solver of mathematical formulas for program verification

LICENSE=	CeCILL-C
LICENSE_NAME=	Ce[a] C[nrs] I[nria] L[ogiciel] L[ibre] C license, version 1
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_powerpc64=	fails to compile: Assembler messages: /tmp/camlasm2822e8.s:10348: Error: operand out of range

BUILD_DEPENDS=	ocaml-zarith>1.2:math/ocaml-zarith \
		ocaml-ocamlgraph>1.8:math/ocaml-ocamlgraph \
		ocaml-lablgtk2>=0:x11-toolkits/ocaml-lablgtk2
RUN_DEPENDS=	ocaml-ocamlgraph>1.8:math/ocaml-ocamlgraph \
		ocaml-lablgtk2>=0:x11-toolkits/ocaml-lablgtk2

GNU_CONFIGURE=	yes
USES=		gmake
USE_OCAML=	yes
ALL_TARGET=	opt pack xpack META
INSTALL_TARGET=	install install-pack-opt install-pack-byte

post-patch:
	@${REINPLACE_CMD} -e '\|^# installation|,\|^# documentation|{ \
		\|cp -f.*$$(BINDIR)|s|cp -f|${INSTALL_SCRIPT}|; \
		\|cp -f.*$$(MANDIR)|s|cp -f|${INSTALL_MAN}|; \
		\|cp -f.*$$(LIBDIR)|s|cp -f|${INSTALL_DATA}|; }' \
		-e 's|make -C|${MAKE_CMD} -C|' \
			${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -Ee 's@(\+|/)(lablgtk2)@\1site-lib/\2@' \
		${WRKSRC}/configure

.include <bsd.port.mk>
