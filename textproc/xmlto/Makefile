# New ports collection makefile for:	xmlto
# Date created:		2003-06-05
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

# The following compile-time options are available:
# WITH_PASSIVETEX	Enable PassiveTex support for DVI/PDF/PS output

PORTNAME=	xmlto
PORTVERSION=	0.0.18
CATEGORIES=	textproc
MASTER_SITES=	http://cyberelk.net/tim/data/xmlto/stable/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Front-end to an XSL toolchain

BUILD_DEPENDS=	${BASH_CMD}:${PORTSDIR}/shells/bash2 \
		${GETOPT_CMD}:${PORTSDIR}/misc/getopt \
		xmllint:${PORTSDIR}/textproc/libxml2 \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		${XSL_DIR}:${PORTSDIR}/textproc/docbook-xsl
RUN_DEPENDS=	${BUILD_DEPENDS}

.if defined(WITH_PASSIVETEX) || exists(${PASSIVETEX})
IGNORE=		with PassiveTex support needs more testing
BUILD_DEPENDS+=	${PASSIVETEX}:${PORTSDIR}/print/passivetex
PLIST_SUB=	PASSIVETEX=""
.else
PLIST_SUB=	PASSIVETEX="@comment "
.endif

USE_BZIP2=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-bash=${BASH_CMD} --with-getopt=${GETOPT_CMD}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

BASH_CMD=	${LOCALBASE}/bin/bash
GETOPT_CMD=	${LOCALBASE}/bin/getopt
PASSIVETEX=	${LOCALBASE}/share/texmf/tex/passivetex
XSL_DIR=	${LOCALBASE}/share/xsl/docbook

MAN1=		xmlif.1 xmlto.1
DOCS=		AUTHORS NEWS

.if !defined(WITH_PASSIVETEX)
post-patch:
	${REINPLACE_CMD} -e '/format\/fo\//d' ${WRKSRC}/Makefile.in
.endif

post-build:
	@${REINPLACE_CMD} -e 's,/usr/bin,${LOCALBASE}/bin,g' \
		${WRKSRC}/format/docbook/txt

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
