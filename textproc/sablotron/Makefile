# New ports collection makefile for:	sablotron
# Date created:		13 Nov 2000
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Sablot
PORTVERSION=	0.96
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://download-2.gingerall.cz/download/sablot/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} sablot-docs-0.81${EXTRACT_SUFX}

PATCH_SITES=	$(MASTER_SITES)
PATCHFILES=	$(DISTNAME).1.patch
PATCH_DIST_STRIP=	-p2

MAINTAINER=	skv@FreeBSD.org

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv \
		expat.4:${PORTSDIR}/textproc/expat2

# If WITH_DISABLE_META is defined sablot will not output the META html tag
#WITH_DISABLE_META=	yes

# Define WITH_ICONV_TYPECAST to typecast the second parameter
# of iconv to char**
#WITH_ICONV_TYPECAST=	yes

INSTALLS_SHLIB=	yes

SHLIB_MAJOR=	69	# API changes counter
PLIST_SUB+=	SHLIB_MAJOR="${SHLIB_MAJOR}" DOCSDIR="share/doc/${PORTNAME}"

CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib \
		LIBTOOL=${LIBTOOL}
USE_GMAKE=	yes
USE_AUTOMAKE=	yes
AUTOMAKE_ARGS=	-a
USE_LIBTOOL=	yes

MAN1=	sabcmd.1

.include <bsd.port.pre.mk>

.if defined(WITHOUT_ADDING_META)
CONFIGURE_ARGS+=	--disable-adding-meta
.endif

.if defined(WITH_ICONV_TYPECAST)
CONFIGURE_ARGS+=	--enable-iconv-typecast
.endif

.if defined(WITHOUT_DOM)
CONFIGURE_ARGS+=	--disable-dom
.endif

.if defined(WITHOUT_DOCUMENT_ERRORS)
CONFIGURE_ARGS+=	--disable-document-errors
.endif

.if defined(WITH_CHECK_LEAKS)
CONFIGURE_ARGS+=	--enable-check-leaks
.endif

.if defined(WITH_DEBUGGER)
CONFIGURE_ARGS+=	--enable-debugger
.endif

WRKSRCDOC=	${WRKDIR}/sablot-docs
DOCSLIST=	README README_JS RELEASE

pre-patch:
	@${PERL} -pi -e \
	's!(?<=libsablot_la_LDFLAGS = -version-info )(\d+):(\d+):\1!${SHLIB_MAJOR}:$$1:${SHLIB_MAJOR}!;' \
		${WRKSRC}/src/engine/Makefile.am

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${DOCSDIR}/jsdom-ref/apidocs
	@${MKDIR} ${DOCSDIR}/sxp/apidocs
	@${INSTALL_DATA} ${DOCSLIST:S!^!${WRKSRC}/!}	${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRCDOC}/*.html		${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRCDOC}/jsdom-ref/*.html	${DOCSDIR}/jsdom-ref
	@${INSTALL_DATA} ${WRKSRCDOC}/jsdom-ref/apidocs/* ${DOCSDIR}/jsdom-ref/apidocs
	@${INSTALL_DATA} ${WRKSRCDOC}/sxp/*.html	${DOCSDIR}/sxp
	@${INSTALL_DATA} ${WRKSRCDOC}/sxp/apidocs/*	${DOCSDIR}/sxp/apidocs
.endif

.include <bsd.port.post.mk>
