PORTNAME=	davmail
DISTVERSION=	6.5.1
CATEGORIES=	mail java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}
DISTNAME=	${PORTNAME}-src-${DISTVERSION}-${REVISION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	POP/IMAP/SMTP/Caldav/Carddav/LDAP Exchange Gateway
WWW=		https://davmail.sourceforge.net/

LICENSE=	GPLv2

USES=		dos2unix java:ant,run tar:tgz

DOS2UNIX_FILES=	build.xml
USE_RC_SUBR=	${PORTNAME}
# 6.5.1
REVISION=	3873
# port build number, same as on DISTNAME
MAKE_ARGS=	-Drevision=${REVISION}
MAKE_ENV+=	"ANT_OPTS=-Dfile.encoding=UTF-8"
ALL_TARGET=	release

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
NO_ARCH=	yes
SUB_FILES=	${PORTNAME}.sh pkg-message

WRKSRC=		${WRKDIR}/${PORTNAME}-src-${DISTVERSION}

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

PLIST_SUB=	VERSION="${DISTVERSION}"

post-patch:
	@${REINPLACE_CMD} -e 's#prefix=\"usr#prefix=\"${PREFIX}#' \
		${WRKSRC}/build.xml

# Azul JRE FX has been disabled by removing the target:
# <antcall target="download-jre"/>
# in files/patch-build.xml patch.
do-install:
	@cd ${WRKSRC}/dist && ${FIND} . -type d \
		-exec ${MKDIR} ${STAGEDIR}${DATADIR}/\{} \;
	@cd ${WRKSRC}/dist && ${FIND} . -type f \
		-not -name "*.deb" \
		-not -name "*.md5" \
		-not -name "*.MD5" \
		-not -name "*.tgz" \
		-not -name "*.exe" \
		-not -name "swt-*.jar" \
		-not -name "*.zip" \
		-not -name "*.war" \
		-not -name "*.rpm" \
		-not -name "*.desktop" \
		-exec ${INSTALL_DATA} \{} ${STAGEDIR}${DATADIR}/\{} \;
	@${FIND} ${STAGEDIR}/${DATADIR} -depth -empty -type d -delete
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/etc/${PORTNAME}.properties \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.properties.sample
	${INSTALL_DATA} ${WRKSRC}/src/desktop/${PORTNAME}.desktop \
		${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
