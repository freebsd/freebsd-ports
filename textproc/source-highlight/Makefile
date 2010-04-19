# Ports collection makefile for:  source-highlight
# Date created:			  24 Aug 2001
# Whom:				  Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	source-highlight
PORTVERSION=	3.1.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	src-highlite

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	C/C++ and Java sources to HTML converter

BUILD_DEPENDS=	exctags:${PORTSDIR}/devel/ctags
LIB_DEPENDS=	boost_regex:${PORTSDIR}/devel/boost-libs

GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"

USE_GMAKE=	yes
USE_LDCONFIG=	yes

MAN1=	check-regexp.1 source-highlight.1 source-highlight-settings.1
INFO=	source-highlight source-highlight-lib

OPTIONS=	BASH	"Support Bash completion"	Off

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
.if ${ARCH} == "sparc64"
BROKEN=		Does not compile with GCC 4.2
.endif
.endif

.if defined(WITH_BASH)
RUN_DEPENDS+=	${LOCALBASE}/etc/bash_completion:${PORTSDIR}/shells/bash-completion
CONFIGURE_ARGS+=	--with-bash-completion
PLIST_SUB+=	BASH=""
.else
CONFIGURE_ARGS+=	--without-bash-completion
PLIST_SUB+=	BASH="@comment "
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" -type f | ${XARGS} ${REINPLACE_CMD} -e \
	's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g'
.if defined(NOPORTDATA)
	@${REINPLACE_CMD} -e '/install-data-am:/,/:/s/install-source_highlightdataDATA//g' \
		${WRKSRC}/doc/Makefile.in ${WRKSRC}/src/Makefile.in
.endif
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/install-data-am:/,/:/s/install-source_highlightdocDATA//g' \
		${WRKSRC}/Makefile.in ${WRKSRC}/doc/Makefile.in ${WRKSRC}/tests/Makefile.in
.endif
.if defined(NOPORTEXAMPLES)
	@${REINPLACE_CMD} -e '/install-data-am:/,/:/s/install-source_highlightlibexampleDATA//g' \
		${WRKSRC}/lib/examples/Makefile.in
.endif

test: build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${_MAKE_JOBS} ${MAKE_ARGS} check)

.include <bsd.port.post.mk>
