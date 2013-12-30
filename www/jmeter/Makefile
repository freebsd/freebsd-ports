# Created by: Ernst de Haan <znerd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	apache-jmeter
PORTVERSION=	2.9
CATEGORIES=	www benchmarks java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	jmeter/binaries
EXTRACT_SUFX=	.tgz

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Functional behaviour load and performance test application

LICENSE=	APACHE20

# These are JAR-files installed by other ports. The list should keep
# growing until all Java applications install just their own JARs -- not
NO_STAGE=	yes
# the 3rd-party ones:
RUN_DEPENDS=	${JAVAJARDIR}/activation.jar:${PORTSDIR}/java/jaf	\
		${JAVAJARDIR}/avalon-framework.jar:${PORTSDIR}/devel/avalon-framework	\
		${JAVAJARDIR}/commons-codec.jar:${PORTSDIR}/java/jakarta-commons-codec	\
		${JAVALIBDIR}/commons-collections.jar:${PORTSDIR}/java/jakarta-commons-collections	\
		${JAVALIBDIR}/commons-httpclient.jar:${PORTSDIR}/java/jakarta-commons-httpclient	\
		${JAVALIBDIR}/commons-io.jar:${PORTSDIR}/devel/jakarta-commons-io \
		${JAVALIBDIR}/commons-lang.jar:${PORTSDIR}/java/jakarta-commons-lang	\
		${JAVAJARDIR}/commons-logging.jar:${PORTSDIR}/java/jakarta-commons-logging	\
		${JAVAJARDIR}/commons-net.jar:${PORTSDIR}/net/jakarta-commons-net	\
		${JAVAJARDIR}/httpclient.jar:${PORTSDIR}/www/httpclient	\
		${JAVAJARDIR}/httpcore.jar:${PORTSDIR}/www/httpcore	\
		${JAVAJARDIR}/httpmime.jar:${PORTSDIR}/www/httpclient	\
		${JAVAJARDIR}/jakarta-oro.jar:${PORTSDIR}/java/jakarta-oro	\
		${JAVAJARDIR}/jdom.jar:${PORTSDIR}/java/jdom	\
		${JAVAJARDIR}/junit.jar:${PORTSDIR}/java/junit	\
		${JAVAJARDIR}/mail.jar:${PORTSDIR}/java/javamail	\
		${JAVAJARDIR}/serializer.jar:${PORTSDIR}/textproc/xalan-j	\
		${JAVAJARDIR}/xalan.jar:${PORTSDIR}/textproc/xalan-j	\
		${JAVAJARDIR}/xercesImpl.jar:${PORTSDIR}/textproc/xerces-j	\
		${JAVAJARDIR}/xml-apis.jar:${PORTSDIR}/textproc/xerces-j	\
		${JAVAJARDIR}/xmlgraphics-commons.jar:${PORTSDIR}/graphics/xmlgraphics-commons	\
		${JAVAJARDIR}/xstream.jar:${PORTSDIR}/textproc/xstream	\
		${JAVASHAREDIR}/rhino/rhino.jar:${PORTSDIR}/lang/rhino

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

.if !defined(NOPORTDOCS)
PORTDOCS=	docs printable_docs README LICENSE
.endif

.include <bsd.port.pre.mk>

do-configure:
	${PRINTF} '\nuser.classpath=' >> ${WRKSRC}/bin/system.properties
.for j in ${RUN_DEPENDS:C/:.*//:M*.jar}
	${PRINTF} '$j:' >> ${WRKSRC}/bin/system.properties
.endfor
	${PRINTF} '\n' >> ${WRKSRC}/bin/system.properties

do-install:
	cd ${WRKSRC} \
	  && ${FIND} ${DATAFILES} -type d -exec ${MKDIR} ${DATADIR}/{} \;
	cd ${WRKSRC} \
	  && ${FIND} ${DATAFILES} -type f -not -name '*.orig' -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} \
	  && ${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${DOCSDIR}/{} \;
	cd ${WRKSRC} \
	  && ${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
.endif
	${INSTALL_SCRIPT} ${WRKDIR}/jmeter.sh ${PREFIX}/bin/jmeter

# For some reason, it is not enough for these three to simply be listed in
# jmeter.properties file. JMeter refuses to start, unless they are found in lib/
BOOTSTRAP_JARS=	avalon-framework xstream commons-io
post-install:
	@${LN} -s ${BOOTSTRAP_JARS:C|.*|${JAVAJARDIR}/&.jar|} ${DATADIR}/lib/

.include <bsd.port.post.mk>
