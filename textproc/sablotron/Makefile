# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Sablot
PORTVERSION=	1.0.3
CATEGORIES=	textproc
MASTER_SITES=	SF/sablotron/sablotron-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML toolkit implementing XSLT 1.0, XPath 1.0 and DOM Level2

LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2

OPTIONS_DEFINE=	DISABLE_META ICONV_TYPECAST DOM DOCUMENT_ERRORS CHECK_LEAKS DEBUGGER DOCS
DISABLE_META_DESC=	Do not output the META html tag
ICONV_TYPECAST_DESC=	Use iconv typecast
DOM_DESC=	Use DOM
DOCUMENT_ERRORS_DESC=	Allow document errors
CHECK_LEAKS_DESC=	Enable memory leaks checking
DEBUGGER_DESC=	Enable debugger
OPTIONS_DEFAULT=	DOM DOCUMENT_ERRORS

DISABLE_META_CONFIGURE_ON=		--disable-adding-meta
ICONV_TYPECAST_CONFIGURE_ENABLE=	iconv-typecast
DOM_CONFIGURE_ENABLE=			dom
DOCUMENT_ERRORS_CONFIGURE_ENABLE=	document-errors
CHECK_LEAKS_CONFIGURE_ENABLE=		check-leaks
DEBUGGER_CONFIGURE_ENABLE=		debugger
DOCS_BUILD_DEPENDS=			p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
DOCS_CONFIGURE_ON=			--with-html-dir=${DOCSDIR}

USE_LDCONFIG=	yes

SHLIB_MAJOR=	70	# API changes counter
PLIST_SUB+=	SHLIB_MAJOR="${SHLIB_MAJOR}"

CONFIGURE_ENV=	LIBTOOL=${LIBTOOL}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lexpat -liconv
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USES=		iconv
GNU_CONFIGURE=	yes
USE_PERL5_BUILD=	yes

MAN1=	sabcmd.1

.include <bsd.port.pre.mk>

DOCSLIST=	README README_JS RELEASE doc/misc/DEBUGGER doc/misc/NOTES

post-patch:
	@${PERL} -pi -e \
	's!(?<=libsablot_la_LDFLAGS = -version-info )(\d+):(\d+):\1!${SHLIB_MAJOR}:$$1:${SHLIB_MAJOR}!;' \
		${WRKSRC}/src/engine/Makefile.in
	@${PERL} -pi -e 's!se // !! if $$. = 407' ${WRKSRC}/src/engine/base.h
.if ! ${PORT_OPTIONS:MDOCS}
	@${PERL} -pi -e 's!(?<=SUBDIRS = )(.*)!man!' ${WRKSRC}/doc/Makefile.in
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "===>   Installing additional documentation for ${PKGNAME}"
	@${INSTALL_DATA} ${DOCSLIST:S!^!${WRKSRC}/!}	${DOCSDIR}
.endif

.include <bsd.port.post.mk>
