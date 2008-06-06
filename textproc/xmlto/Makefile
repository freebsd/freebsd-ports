# New ports collection makefile for:	xmlto
# Date created:		2003-06-05
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	xmlto
PORTVERSION=	0.0.20
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://cyberelk.net/tim/data/xmlto/stable/
# Master Site is subject to change with 0.0.21 release

MAINTAINER=	matthias.andree@gmx.de
COMMENT=	Front-end to an XSL toolchain

BUILD_DEPENDS=	${BASH_CMD}:${PORTSDIR}/shells/bash \
		${GETOPT_CMD}:${PORTSDIR}/misc/getopt \
		xmllint:${PORTSDIR}/textproc/libxml2 \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		${XSL_DIR}:${PORTSDIR}/textproc/docbook-xsl
RUN_DEPENDS=	${BUILD_DEPENDS}

OPTIONS=	PASSIVETEX "Enable PassiveTeX support for DVI/PS/PDF" OFF

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

post-patch:
.for i in docbook/htmlhelp docbook/xhtml-nochunks docbook/javahelp \
	docbook/html docbook/html-nochunks docbook/xhtml docbook/fo \
	docbook/man fo/dvi fo/pdf
	@${REINPLACE_CMD} -e 's|-a|-PpR|' ${WRKSRC}/format/${i}
.endfor
.if !defined(WITH_PASSIVETEX)
	@${REINPLACE_CMD} -e '/format\/fo\//d' ${WRKSRC}/Makefile.in
.endif

post-build:
	@${REINPLACE_CMD} -e 's,/usr/bin,${LOCALBASE}/bin,g' \
		${WRKSRC}/format/docbook/txt

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
