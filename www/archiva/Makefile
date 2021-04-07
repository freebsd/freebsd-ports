PORTNAME=	archiva
PORTVERSION=	2.2.3
CATEGORIES=	www java
MASTER_SITES=	APACHE/${PORTNAME}/${PORTVERSION}/binaries
DISTNAME=	apache-${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	freebsd@dussan.org
COMMENT=	Extensible repository management software

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	javaservicewrapper:sysutils/javaservicewrapper

USES=		cpe
CPE_VENDOR=	apache

USE_JAVA=	yes

USE_RC_SUBR=	${PORTNAME}

PLIST_SUB=	ARCHIVA_CONF=${PREFIX}/${PORTNAME} \
		ARCHIVA_GROUP=${GROUPS} \
		ARCHIVA_HOME=${DATADIR} \
		ARCHIVA_USER=${USERS}

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/apache-${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} \
		-e 's|%%BASEDIR%%|${PREFIX}/${PORTNAME}|' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		-e 's|%%USER%%|${USERS}|' \
		-e 's|%%WRAPPER_CMD%%|${LOCALBASE}/bin/wrapper|' \
		${WRKSRC}/bin/${PORTNAME}
	@${REINPLACE_CMD} \
		-e 's|%%ARCHIVA_BASE%%|${PREFIX}/${PORTNAME}|' \
		-e 's|%%DIR%%|${DATADIR}|' \
		-e 's|%%JAVA%%|${JAVA}|' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		-e 's|%%REPO_DIR%%|${DATADIR}|' \
		-e 's|%%WRAPPER_DIR%%|${LOCALBASE}/lib/javaservicewrapper|' \
		-e 's|%%WRAPPER_JAR%%|${LOCALBASE}/lib/javaservicewrapper/lib/wrapper.jar|' \
		${WRKSRC}/conf/wrapper.conf
	@${RM} \
		${WRKSRC}/bin/${PORTNAME}.bak \
		${WRKSRC}/bin/${PORTNAME}.bat \
		${WRKSRC}/bin/${PORTNAME}.orig \
		${WRKSRC}/bin/wrapper-linux-x86-32 \
		${WRKSRC}/bin/wrapper-linux-x86-64 \
		${WRKSRC}/bin/wrapper-macosx-universal-32 \
		${WRKSRC}/bin/wrapper-macosx-universal-64 \
		${WRKSRC}/bin/wrapper-solaris-sparc-32 \
		${WRKSRC}/bin/wrapper-solaris-sparc-64 \
		${WRKSRC}/bin/wrapper-solaris-x86-32 \
		${WRKSRC}/bin/wrapper-windows-x86-32.exe \
		${WRKSRC}/bin/wrapper-windows-x86-64.exe \
		${WRKSRC}/conf/wrapper.conf.bak \
		${WRKSRC}/conf/wrapper.conf.orig \
		${WRKSRC}/lib/libwrapper-linux-x86-32.so \
		${WRKSRC}/lib/libwrapper-linux-x86-64.so \
		${WRKSRC}/lib/libwrapper-macosx-universal-32.jnilib \
		${WRKSRC}/lib/libwrapper-macosx-universal-64.jnilib \
		${WRKSRC}/lib/libwrapper-solaris-sparc-32.so \
		${WRKSRC}/lib/libwrapper-solaris-sparc-64.so \
		${WRKSRC}/lib/libwrapper-solaris-x86-32.so \
		${WRKSRC}/lib/wrapper-windows-x86-32.dll \
		${WRKSRC}/lib/wrapper-windows-x86-64.dll \
		${WRKSRC}/lib/wrapper.jar

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
.for dir in conf data logs temp
	${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}/${dir}
.endfor
	(cd ${STAGEDIR}${DATADIR}/conf && ${FIND} . -type f -exec \
		${INSTALL_DATA} '{}' ${STAGEDIR}${PREFIX}/${PORTNAME}/conf/'{}'.sample \;)

.include <bsd.port.mk>
