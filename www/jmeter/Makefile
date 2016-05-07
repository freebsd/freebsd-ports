# Created by: Ernst de Haan <znerd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	apache-jmeter
PORTVERSION=	2.11
CATEGORIES=	www benchmarks java
MASTER_SITES=	APACHE/jmeter/binaries

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Functional behaviour load and performance test application

LICENSE=	APACHE20

# These are JAR-files installed by other ports. The list should keep
# growing until all Java applications install just their own JARs -- not
# the 3rd-party ones:
RUN_DEPENDS=	${JAVAJARDIR}/activation.jar:java/jaf	\
		${JAVAJARDIR}/avalon-framework.jar:devel/avalon-framework	\
		${JAVAJARDIR}/commons-codec.jar:java/jakarta-commons-codec	\
		${JAVALIBDIR}/commons-collections.jar:java/jakarta-commons-collections	\
		${JAVALIBDIR}/commons-httpclient.jar:java/jakarta-commons-httpclient	\
		${JAVALIBDIR}/commons-io.jar:devel/jakarta-commons-io \
		${JAVALIBDIR}/commons-lang.jar:java/jakarta-commons-lang	\
		${JAVAJARDIR}/commons-logging.jar:java/jakarta-commons-logging	\
		${JAVAJARDIR}/commons-net.jar:net/jakarta-commons-net	\
		${JAVAJARDIR}/httpclient.jar:www/httpclient	\
		${JAVAJARDIR}/httpcore.jar:www/httpcore	\
		${JAVAJARDIR}/httpmime.jar:www/httpclient	\
		${JAVAJARDIR}/jakarta-oro.jar:java/jakarta-oro	\
		${JAVAJARDIR}/jdom.jar:java/jdom	\
		${JAVAJARDIR}/junit.jar:java/junit	\
		${JAVAJARDIR}/mail.jar:java/javamail	\
		${JAVAJARDIR}/serializer.jar:textproc/xalan-j	\
		${JAVAJARDIR}/slf4j-api.jar:devel/slf4j	\
		${LOCALBASE}/share/slf4j/slf4j-nop.jar:devel/slf4j	\
		${JAVAJARDIR}/xalan.jar:textproc/xalan-j	\
		${JAVAJARDIR}/xercesImpl.jar:textproc/xerces-j	\
		${JAVAJARDIR}/xml-apis.jar:textproc/xerces-j	\
		${JAVAJARDIR}/xmlgraphics-commons.jar:graphics/xmlgraphics-commons	\
		${JAVAJARDIR}/xstream.jar:textproc/xstream	\
		${JAVASHAREDIR}/rhino/rhino.jar:lang/rhino

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

# For some reason, it is not enough for these three to simply be listed in
# jmeter.properties file. JMeter refuses to start, unless they are found in lib/
BOOTSTRAP_JARS=	avalon-framework xstream commons-io
post-install:
	@${LN} -s ${BOOTSTRAP_JARS:C|.*|${JAVAJARDIR}/&.jar|} ${STAGEDIR}${DATADIR}/lib/

.include <bsd.port.post.mk>
