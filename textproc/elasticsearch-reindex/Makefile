# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	elasticsearch-reindex
# the version is in pom.xml
# https://github.com/karussell/elasticsearch-reindex/commit/f85f3eebce49d6bf3fcddbbcacbe2b81ee253ca3
PORTVERSION=	0.90.5
#PORTREVISION=	1
CATEGORIES=	textproc java

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	Simple re-indexing tool for elasticsearch

BUILD_DEPENDS=	${LOCALBASE}/share/java/maven3/bin/mvn:${PORTSDIR}/devel/maven3

USE_JAVA=	yes
PLIST_SUB=	PORTNAME="${PORTNAME}" \
			PORTVERSION="${PORTVERSION}"
SUB_LIST+=	PORTNAME="${PORTNAME}"
SUB_FILES=	pkg-message

USE_GITHUB=	yes
GH_ACCOUNT=	karussell
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	1735450

do-build:
	(cd ${WRKSRC} && mvn -DskipTests clean package)

do-install:
	${INSTALL} -d ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/target/${PORTNAME}-${PORTVERSION}.zip ${DATADIR}/

# XXX mvn downloads lots of files and the build process might not be
# repeatable. see:
#
#   archivers/snappy-java
#   databases/jasperserver
#
# there might be a wrok around but i don't bother for a helper plugin.
.include <bsd.port.mk>
