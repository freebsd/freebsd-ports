# New ports collection makefile for:	TclDOM-libxml2
# Date created:				28 April 2008
# Whom:					Frank Fenor <frank@fenor.de>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-libxml2

MAINTAINER=	frank@fenor.de
COMMENT=	DOM API for Tcl using libxml2

BUILD_DEPENDS=	${LOCALBASE}/lib/TclxmlConfig.sh:${PORTSDIR}/devel/tclxml \
		${LOCALBASE}/include/tclxml-libxml2/tclxml-libxml2Decls.h:${PORTSDIR}/devel/tclxml-libxml2
RUN_DEPENDS=	${LOCALBASE}/lib/Tclxml${PORTVERSION}/libTclxml${PORTVERSION}.so:${PORTSDIR}/devel/tclxml \
		${LOCALBASE}/lib/TclXML_libxml2${PORTVERSION}/libTclXML_libxml2${PORTVERSION}.so:${PORTSDIR}/devel/tclxml-libxml2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src-libxml2
PATCHDIR=	${.CURDIR}/files
USE_LDCONFIG=	yes
NOPORTDOCS=	yes
PLIST_SUB=	VER=${PORTVERSION}

MASTERDIR=	${.CURDIR}/../tcldom

post-build:
	${REINPLACE_CMD} -e 's|@tcldomxml_LIB_FILE@|libtcldom_libxml2${PORTVERSION}.so|' \
	-e 's|@tcldomxml_LIB_SPEC@|${LOCALBASE}/lib/tcldom_libxml2${PORTVERSION}/libtcldom_libxml2${PORTVERSION}.so|' \
	-e 's|@tcldomxmlstub_LIB_FILE@|libtcldom_libxml2stub${PORTVERSION}.a|' \
	-e 's|@tcldomxml_STUB_LIB_SPEC@|${LOCALBASE}/lib/tcldom_libxml2${PORTVERSION}/libtcldom_libxml2stub${PORTVERSION}.a|' \
	-e 's|@tcldomxml_STUB_LIB_PATH@|${LOCALBASE}/lib/tcldom_libxml2${PORTVERSION}|' \
	${WRKSRC}/tcldomlibxml2Config.sh

.include	"${MASTERDIR}/Makefile"
