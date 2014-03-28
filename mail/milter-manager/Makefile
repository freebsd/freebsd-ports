# Created by: Hirohisa Yamaguchi <umq@ueo.co.jp>
# $FreeBSD$

PORTNAME=	milter-manager
PORTVERSION=	1.8.6
CATEGORIES=	mail ruby
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME:S/-/%20/}/${PORTVERSION}

MAINTAINER=	umq@ueo.co.jp
COMMENT=	A super milter that can invoke several milters selectively

LICENSE=	AGPLv3 GFDL GPLv3 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	rubygem-glib2>0:${PORTSDIR}/devel/rubygem-glib2
LIB_DEPENDS=	ev:${PORTSDIR}/devel/libev
RUN_DEPENDS=	rubygem-glib2>0:${PORTSDIR}/devel/rubygem-glib2

USE_RC_SUBR=	milter-manager
GNU_CONFIGURE=	yes
MAKE_ARGS+=	pkgconfigdir=${PREFIX}/libdata/pkgconfig
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		--with-libev \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"
USES=		gmake pkgconfig
USE_GNOME=	glib20 intltool
USE_LDCONFIG=	yes
USE_RUBY=	yes

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

MANLANG=	"" ja
MAN1=		milter-manager-log-analyzer.1 milter-manager.1 milter-performance-check.1 \
		milter-report-statistics.1 milter-test-client.1 milter-test-server.1
PORTDOCS=	*
PORTEXAMPLES=	*
PORTDATA=	*

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=--with-html-dir=${DOCSDIR}
.else
CONFIGURE_ARGS+=--with-html-dir=${WRKDIR}/doc
.endif
.ifdef NOPORTEXAMPLES
EXAMPLESDIR=	${WRKDIR}/examples
.endif
.ifdef NOPORTDATA
DATADIR=	${WRKDIR}/data
.endif

post-patch:
	${FIND} ${WRKSRC} -type f -name Makefile.in -exec \
	${REINPLACE_CMD} -e "s#\$$(datadir)/@PACKAGE@#${DATADIR}#" \
			 -e "s#\$$(datarootdir)/\$$(PACKAGE)#${DATADIR}#" {} +
	${REINPLACE_CMD} -e "s#\\\\\$$(pkgdatadir)/sample#${EXAMPLESDIR}#" ${WRKSRC}/configure

.include <bsd.port.mk>
