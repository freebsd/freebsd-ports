# $FreeBSD$

PORTNAME=	nmsg
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://dl.farsightsecurity.com/dist/nmsg/ \
		LOCAL/truckman/farsight

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Network message encapsulation system

LICENSE=	APACHE20

LIB_DEPENDS=	libprotobuf-c.so:${PORTSDIR}/devel/protobuf-c \
		libxs.so:${PORTSDIR}/devel/libxs \
		libwdns.so:${PORTSDIR}/dns/wdns

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gmake libtool pathfix pkgconfig
CONFIGURE_ARGS=	--with-pkgconfigdir='$${exec_prefix}/libdata/pkgconfig'
INSTALL_TARGET=	install-strip

PORTDOCS=	*

# The DOXYGEN option is best effort.
# If doxygen is installed, it will get used if the option is set to NO.
OPTIONS_DEFINE=		DOXYGEN EXAMPLES MANPAGES
OPTIONS_DEFAULT=	DOXYGEN EXAMPLES MANPAGES
OPTIONS_SUB=		yes

ALL_TARGET=	all
DOXYGEN_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
DOXYGEN_ALL_TARGET=	html-local
DOCBOOK_XML=	${LOCALBASE}/share/xml/docbook/4.2
DOCBOOK_XSL_NS=	${LOCALBASE}/share/doc/docbook-xsl-ns/html/docbook.css.source.html
MANPAGES_BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt \
			docbook-xml>0:${PORTSDIR}/textproc/docbook-xml \
			${DOCBOOK_XSL_NS}:${PORTSDIR}/textproc/docbook-xsl-ns
MANPAGES_CONFIGURE_WITH=	xsltproc

.include <bsd.port.options.mk>

# The version of binutils in base does not understand the crc32
# instructions used in this code on amd64.  Use gcc from ports
# to get a more capable version of binutils.
.if (${OSVERSION} < 900000 &&  ${ARCH} == amd64)
USE_GCC=	yes
.endif

post-install:
.if ${PORT_OPTIONS:MDOXYGEN}
	(cd ${WRKSRC}/doc/doxygen && \
	${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && \
	${INSTALL_DATA} *.c *.py ${STAGEDIR}${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
