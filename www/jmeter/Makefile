# Created by: Ernst de Haan <znerd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	apache-jmeter
PORTVERSION=	2.11
PORTREVISION=	2
CATEGORIES=	www benchmarks java
MASTER_SITES=	APACHE/jmeter/binaries

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Functional behaviour load and performance test application

LICENSE=	APACHE20

# These are JAR-files installed by other ports. The list should keep
# growing until all Java applications install just their own JARs -- not
# the 3rd-party ones:
RUN_DEPENDS=	\
		${JAVALIBDIR}/avalon-framework.jar:devel/avalon-framework	\
		${JAVALIBDIR}/commons-codec.jar:java/jakarta-commons-codec	\
		${JAVALIBDIR}/commons-collections.jar:java/apache-commons-collections	\
		${JAVALIBDIR}/commons-httpclient.jar:java/jakarta-commons-httpclient	\
		${JAVALIBDIR}/commons-io.jar:devel/apache-commons-io \
		${JAVALIBDIR}/commons-lang.jar:java/apache-commons-lang	\
		${JAVALIBDIR}/commons-logging.jar:java/apache-commons-logging	\
		${JAVALIBDIR}/commons-net.jar:net/apache-commons-net	\
		${JAVALIBDIR}/httpclient.jar:www/httpclient	\
		${JAVALIBDIR}/httpcore.jar:www/httpcore	\
		${JAVALIBDIR}/httpmime.jar:www/httpclient	\
		${JAVALIBDIR}/jakarta-oro.jar:java/jakarta-oro	\
		${JAVALIBDIR}/jdom.jar:java/jdom	\
		${JAVALIBDIR}/junit.jar:java/junit	\
		${JAVALIBDIR}/mail.jar:java/javamail	\
		${JAVALIBDIR}/serializer.jar:textproc/xalan-j	\
		${JAVALIBDIR}/slf4j-api.jar:devel/slf4j	\
		${LOCALBASE}/share/slf4j/slf4j-nop.jar:devel/slf4j	\
		${JAVALIBDIR}/xalan.jar:textproc/xalan-j	\
		${JAVALIBDIR}/xercesImpl.jar:textproc/xerces-j	\
		${JAVALIBDIR}/xml-apis.jar:textproc/xerces-j	\
		${JAVALIBDIR}/xmlgraphics-commons.jar:graphics/xmlgraphics-commons	\
		${JAVALIBDIR}/xstream.jar:textproc/xstream	\
		${LOCALBASE}/share/java/rhino/rhino.jar:lang/rhino

USES=		tar:tgz
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
SUB_FILES=	jmeter.sh
DATAFILES=	bin extras lib
# Do not even extract the MS-DOS files nor the JARs,
# that are already provided by other ports:
EXTRACT_AFTER_ARGS=	--exclude '*.bat' --exclude '*.cmd'	\
	${RUN_DEPENDS:M*.jar*:C|.*/(.+).jar:.*|--exclude '\1-*.jar'|}	\
	--exclude 'oro-*.jar'

OPTIONS_DEFINE=	DOCS

PORTDOCS=	docs printable_docs README LICENSE

.include <bsd.port.pre.mk>

do-configure:
	${PRINTF} '\nuser.classpath=' >> ${WRKSRC}/bin/system.properties
.for j in ${RUN_DEPENDS:C/:.*//:M*.jar}
	${PRINTF} '$j:' >> ${WRKSRC}/bin/system.properties
.endfor
	${PRINTF} '\n' >> ${WRKSRC}/bin/system.properties

# For some reason, it is not enough for these three to simply be listed in
# jmeter.properties file. JMeter refuses to start, unless they are found in lib/
BOOTSTRAP_JARS=	avalon-framework xstream commons-io
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
