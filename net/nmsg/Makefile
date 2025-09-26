PORTNAME=	nmsg
PORTVERSION=	1.3.3
PORTREVISION=	0
CATEGORIES=	net
MASTER_SITES=	FARSIGHT LOCAL/truckman/farsight

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Network message encapsulation system
WWW=		https://github.com/farsightsec/nmsg

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libprotobuf-c.so:devel/protobuf-c \
		libwdns.so:dns/wdns

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USES=		gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes
USE_PERL5=	build
CONFIGURE_ARGS=	--with-pkgconfigdir='$${exec_prefix}/libdata/pkgconfig'
INSTALL_TARGET=	install-strip

PORTDOCS=	*

# The DOXYGEN option is best effort.
# If doxygen is installed, it will get used if the option is set to NO.
OPTIONS_DEFINE=		JSON_C KAFKA ZEROMQ DOXYGEN EXAMPLES MANPAGES DOCS
OPTIONS_DEFAULT=	JSON_C KAFKA ZEROMQ DOXYGEN MANPAGES
OPTIONS_SUB=		yes

JSON_C_DESC=		JSON support via libjson-c
JSON_C_CONFIGURE_WITH=	json-c
JSON_C_LIB_DEPENDS=	libjson-c.so:devel/json-c
KAFKA_DESC=		Kafka I/O in JSON and binary forms
KAFKA_CONFIGURE_WITH=	librdkafka
KAFKA_LIB_DEPENDS=	librdkafka.so:net/librdkafka
ZEROMQ_DESC=		ZeroMQ support
ZEROMQ_CONFIGURE_WITH=	libzmq
ZEROMQ_LIB_DEPENDS=	libzmq.so:net/libzmq4

ALL_TARGET=	all
DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_USES=		perl5
DOXYGEN_ALL_TARGET=	html-local
DOCBOOK_XML=	${LOCALBASE}/share/xml/docbook/4.2
MANPAGES_BUILD_DEPENDS=	xsltproc:textproc/libxslt \
			docbook-xml>0:textproc/docbook-xml \
			docbook-xsl-ns>0:textproc/docbook-xsl-ns
MANPAGES_CONFIGURE_WITH=	xsltproc

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README.md README.FILTERS.md \
		${STAGEDIR}${DOCSDIR}

post-install-DOXYGEN-on:
	(cd ${WRKSRC}/doc/doxygen && \
	${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && \
	${INSTALL_DATA} *.c *.py ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
