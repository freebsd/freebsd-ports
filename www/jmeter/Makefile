PORTNAME=	apache-jmeter
DISTVERSION=	5.6.3
PORTREVISION=	1
CATEGORIES=	www benchmarks java
MASTER_SITES=	https://archive.apache.org/dist/jmeter/binaries/

MAINTAINER=	ports@virtual-estates.net
COMMENT=	Functional behaviour load and performance test application
WWW=		https://jmeter.apache.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

# These are JAR-files installed by other ports. The list should keep
# growing until all Java applications install just their own JARs -- not
# the 3rd-party ones:
_JAVADIR=	${LOCALBASE}/share/java
RUN_DEPENDS=	\
		${_JAVADIR}/batik/lib/batik-anim-1.18.jar:graphics/batik \
		${_JAVADIR}/batik/lib/batik-awt-util-1.18.jar:graphics/batik \
		${_JAVADIR}/batik/lib/batik-bridge-1.18.jar:graphics/batik \
		${_JAVADIR}/batik/lib/batik-codec-1.18.jar:graphics/batik \
		${_JAVADIR}/batik/lib/batik-constants-1.18.jar:graphics/batik \
		${_JAVADIR}/batik/lib/batik-css-1.18.jar:graphics/batik \
		${_JAVADIR}/batik/lib/batik-dom-1.18.jar:graphics/batik \
		${_JAVADIR}/batik/lib/batik-ext-1.18.jar:graphics/batik \
		${_JAVADIR}/batik/lib/batik-gvt-1.18.jar:graphics/batik \
		${_JAVADIR}/batik/lib/batik-i18n-1.18.jar:graphics/batik \
		${_JAVADIR}/batik/lib/batik-parser-1.18.jar:graphics/batik \
		${_JAVADIR}/batik/lib/batik-script-1.18.jar:graphics/batik \
		${_JAVADIR}/batik/lib/batik-shared-resources-1.18.jar:graphics/batik \
		${_JAVADIR}/batik/lib/batik-svg-dom-1.18.jar:graphics/batik \
		${_JAVADIR}/batik/lib/batik-svggen-1.18.jar:graphics/batik \
		${_JAVADIR}/batik/lib/batik-transcoder-1.18.jar:graphics/batik \
		${_JAVADIR}/batik/lib/batik-util-1.18.jar:graphics/batik \
		${_JAVADIR}/batik/lib/batik-xml-1.18.jar:graphics/batik \
		${JAVALIBDIR}/commons-codec.jar:java/apache-commons-codec \
		${JAVALIBDIR}/commons-collections.jar:java/apache-commons-collections \
		${JAVALIBDIR}/commons-collections4.jar:java/apache-commons-collections4	\
		${JAVALIBDIR}/commons-dbcp.jar:java/apache-commons-dbcp \
		${JAVALIBDIR}/commons-io.jar:devel/apache-commons-io \
		${JAVALIBDIR}/commons-lang3.jar:java/apache-commons-lang3 \
		${JAVALIBDIR}/commons-logging.jar:java/apache-commons-logging \
		${JAVALIBDIR}/commons-math.jar:math/apache-commons-math \
		${JAVALIBDIR}/commons-net.jar:net/apache-commons-net \
		${JAVALIBDIR}/commons-pool.jar:java/apache-commons-pool \
		${JAVALIBDIR}/dnsjava.jar:dns/dnsjava \
		${JAVALIBDIR}/httpclient.jar:www/httpclient \
		${JAVALIBDIR}/httpasyncclient.jar:www/httpasyncclient \
		${JAVALIBDIR}/httpcore.jar:www/httpcore \
		${JAVALIBDIR}/httpcore-nio.jar:www/httpcore \
		${JAVALIBDIR}/httpmime.jar:www/httpclient \
		${JAVALIBDIR}/jakarta-oro.jar:java/jakarta-oro \
		${_JAVADIR}/slf4j/jcl-over-slf4j.jar:devel/slf4j \
		${JAVALIBDIR}/junit.jar:java/junit \
		${JAVALIBDIR}/log4j-1.2-api.jar:devel/apache-log4j2 \
		${JAVALIBDIR}/log4j-api.jar:devel/apache-log4j2 \
		${JAVALIBDIR}/log4j-core.jar:devel/apache-log4j2 \
		${JAVALIBDIR}/log4j-slf4j-impl.jar:devel/apache-log4j2 \
		${JAVALIBDIR}/mail.jar:java/javamail \
		${_JAVADIR}/rhino/rhino.jar:lang/rhino \
		saxon-he>=12:textproc/saxon-he \
		${JAVALIBDIR}/serializer.jar:textproc/xalan-j \
		${_JAVADIR}/slf4j/slf4j-api.jar:devel/slf4j \
		${JAVALIBDIR}/xalan.jar:textproc/xalan-j \
		${JAVALIBDIR}/xercesImpl.jar:textproc/xerces-j \
		${JAVALIBDIR}/xml-apis.jar:textproc/xerces-j \
		${_JAVADIR}/xml-commons/xml-apis-ext.jar:textproc/xml-commons \
		${JAVALIBDIR}/xmlgraphics-commons.jar:graphics/xmlgraphics-commons \
		${JAVALIBDIR}/xstream.jar:textproc/xstream

USES=		java tar:tgz
JAVA_VERSION=	17+

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
# Do not even extract the MS-DOS files nor the JARs,
# that are already provided by other ports:
EXTRACT_AFTER_ARGS=	--exclude '*.bat' --exclude '*.cmd' \
			${RUN_DEPENDS:M*.jar*:C|.*/(.+).jar:.*|--exclude '\1-*.jar'|} \
			--exclude 'Saxon-HE-*.jar' --exclude 'batik-*.jar' \
			--exclude 'commons-dbcp2*.jar' --exclude 'commons-math3-*.jar' \
			--exclude 'commons-pool2*.jar' --exclude 'oro-*.jar'

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	jmeter.sh
DATAFILES=	bin extras lib

PORTDOCS=	NOTICE README.md docs printable_docs

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

do-configure:
	${PRINTF} '\nuser.classpath=' >> ${WRKSRC}/bin/system.properties
.for j in ${RUN_DEPENDS:C/:.*//:M*.jar}
	${PRINTF} '$j:' >> ${WRKSRC}/bin/system.properties
.endfor
	${PRINTF} '\n' >> ${WRKSRC}/bin/system.properties

# For some reason, it is not enough for these three to simply be listed in
# jmeter.properties file. JMeter refuses to start, unless they are found in lib/
BOOTSTRAP_JARS=	jakarta-oro log4j-1.2-api log4j-api log4j-core log4j-slf4j-impl slf4j-api
do-install:
	cd ${WRKSRC} \
	  && ${FIND} ${DATAFILES} -type d -exec ${MKDIR} ${STAGEDIR}/${DATADIR}/{} \;
	cd ${WRKSRC} \
	  && ${FIND} ${DATAFILES} -type f -not -name '*.orig' -exec ${INSTALL_DATA} {} ${STAGEDIR}${DATADIR}/{} \;
	cd ${WRKSRC} \
	  && ${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${STAGEDIR}${DOCSDIR}/{} \;
	cd ${WRKSRC} \
	  && ${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/{} \;
	${INSTALL_SCRIPT} ${WRKDIR}/jmeter.sh ${STAGEDIR}${PREFIX}/bin/jmeter

	@${LN} -s ${BOOTSTRAP_JARS:C|.*|${JAVAJARDIR}/&.jar|} ${STAGEDIR}${DATADIR}/lib/

.include <bsd.port.post.mk>
