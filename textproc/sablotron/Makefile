# New ports collection makefile for:	sablotron
# Date created:		13 Nov 2000
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Sablot
PORTVERSION=	1.0.3
CATEGORIES=	textproc
MASTER_SITES=	http://download-1.gingerall.cz/download/sablot/

MAINTAINER=	skv@FreeBSD.org
COMMENT=	XML toolkit implementing XSLT 1.0, XPath 1.0 and DOM Level2

LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2

OPTIONS=	DISABLE_META "Do not output the META html tag" off \
		ICONV_TYPECAST "Use iconv typecast" off \
		DOM "Use DOM" on \
		DOCUMENT_ERRORS "Allow document errors" on \
		CHECK_LEAKS "Enable memory leaks checking" off \
		DEBUGGER "Enable debugger" off

USE_LDCONFIG=	yes

SHLIB_MAJOR=	70	# API changes counter
PLIST_SUB+=	SHLIB_MAJOR="${SHLIB_MAJOR}"

CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include LIBTOOL=${LIBTOOL} \
		LDFLAGS="-L${LOCALBASE}/lib -lexpat -liconv"
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_PERL5_BUILD=	yes

MAN1=	sabcmd.1

.include <bsd.port.pre.mk>

.if defined(WITH_DISABLE_META)
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

.ifndef(NOPORTDOCS)
BUILD_DEPENDS+=		${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
CONFIGURE_ARGS+=	--with-html-dir=${DOCSDIR}
.endif

DOCSLIST=	README README_JS RELEASE doc/misc/DEBUGGER doc/misc/NOTES

post-patch:
	@${PERL} -pi -e \
	's!(?<=libsablot_la_LDFLAGS = -version-info )(\d+):(\d+):\1!${SHLIB_MAJOR}:$$1:${SHLIB_MAJOR}!;' \
		${WRKSRC}/src/engine/Makefile.in
	@${PERL} -pi -e 's!se // !! if $$. = 407' ${WRKSRC}/src/engine/base.h
.if defined(NOPORTDOCS)
	@${PERL} -pi -e 's!(?<=SUBDIRS = )(.*)!man!' ${WRKSRC}/doc/Makefile.in
.endif

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing additional documentation for ${PKGNAME}"
	@${INSTALL_DATA} ${DOCSLIST:S!^!${WRKSRC}/!}	${DOCSDIR}
.endif

.include <bsd.port.post.mk>
