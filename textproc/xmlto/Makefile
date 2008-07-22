# New ports collection makefile for:	xmlto
# Date created:		2003-06-05
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	xmlto
PORTVERSION=	0.0.21
CATEGORIES=	textproc
MASTER_SITES=	https://fedorahosted.org/releases/x/m/xmlto/

MAINTAINER=	matthias.andree@gmx.de
COMMENT=	Front-end to an XSL toolchain

BUILD_DEPENDS=	${BASH_CMD}:${PORTSDIR}/shells/bash \
		${GETOPT_CMD}:${PORTSDIR}/misc/getopt \
		xmllint:${PORTSDIR}/textproc/libxml2 \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		${XSL_DIR}:${PORTSDIR}/textproc/docbook-xsl
RUN_DEPENDS=	${BUILD_DEPENDS}

OPTIONS=	PASSIVETEX "Enable PassiveTeX support for DVI/PS/PDF" OFF \
		FOP "Add dependency on FOP" OFF \
		LIBPAPER "Add dependency on libpaper" OFF \
		DBLATEX "Add dependency on Dblatex (EXPERIMENTAL)" OFF

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-bash=${BASH_CMD} --with-getopt=${GETOPT_CMD}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

BASH_CMD=	${LOCALBASE}/bin/bash
GETOPT_CMD=	${LOCALBASE}/bin/getopt
XSL_DIR=	${LOCALBASE}/share/xsl/docbook

MAN1=		xmlif.1 xmlto.1
PORTDOCS=	AUTHORS COPYING ChangeLog NEWS THANKS
# these two documentation files do not convey information useful for
# the FreeBSD port at this time:
# PORTDOCS+=	FAQ README

.include <bsd.port.pre.mk>

.if defined(WITH_PASSIVETEX)
BUILD_DEPENDS+=	${LOCALBASE}/share/texmf-local/tex/passivetex/fotex.sty:${PORTSDIR}/print/passivetex
RUN_DEPENDS+=	${LOCALBASE}/share/texmf-local/tex/passivetex/fotex.sty:${PORTSDIR}/print/passivetex
PLIST_SUB=	PASSIVETEX=""
.else
PLIST_SUB=	PASSIVETEX="@comment "
.endif

.if defined(WITH_FOP)
RUN_DEPENDS+=	${LOCALBASE}/bin/fop:${PORTSDIR}/textproc/fop
.endif

.if defined(WITH_LIBPAPER)
RUN_DEPENDS+=	${LOCALBASE}/bin/paperconf:${PORTSDIR}/print/libpaper
.endif

.if defined(WITH_DBLATEX)
RUN_DEPENDS+=	${LOCALBASE}/bin/dblatex:${PORTSDIR}/textproc/dblatex
.endif

post-patch:
	@${REINPLACE_CMD} -E -e 's,/usr/bin/(dblatex|fop|links|lynx|paperconf|w3m),${LOCALBASE}/bin/\1,g' \
		${WRKSRC}/xmlto.in \
		${WRKSRC}/format/docbook/txt
.if !defined(WITH_PASSIVETEX)
	@${REINPLACE_CMD} -e '/format\/fo\//d' ${WRKSRC}/Makefile.in
.endif

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
