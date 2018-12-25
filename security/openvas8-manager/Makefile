# $FreeBSD$

PORTNAME?=	openvas8-manager
PORTVERSION?=	6.0.11
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES?=	http://wald.intevation.org/frs/download.php/2445/
DISTNAME=	${PORTNAME:S/${OPENVAS_VER}//}-${PORTVERSION}
DIST_SUBDIR=	openvas${OPENVAS_VER}

MAINTAINER=	acm@FreeBSD.org
COMMENT?=	OpenVAS 8 manager

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-SQL-Translator>=0:databases/p5-SQL-Translator
LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libgpgme.so:security/gpgme \
		libgcrypt.so:security/libgcrypt \
		libopenvas_base.so:security/openvas${OPENVAS_VER}-libraries
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		wget:ftp/wget

CONFLICTS?=	${PORTNAME:S/${OPENVAS_VER}/9/}-*

USES=		cmake gnome pkgconfig
USE_GNOME=	glib20 libxslt:run
PGSQL_USES=	pgsql
SQLITE3_USES=	sqlite
PGSQL_CMAKE_ON+=-DBACKEND:STRING="POSTGRESQL"
SQLITE3_CMAKE_ON+=-DBACKEND:STRING="SQLITE3"
USE_RC_SUBR=	openvasmd
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:S/${OPENVAS_VER}//}
ETCDIR=		${PREFIX}/etc/openvas
REINPLACE_ARGS=	-i ''

OPENVAS_VER?=	8

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=SQLITE3
OPTIONS_SUB=	yes
OPTIONS_SINGLE_DATABASE=SQLITE3 PGSQL
OPTIONS_SINGLE=		DATABASE
DATABASE_DESC=		Database support

post-patch:
	@${REINPLACE_CMD} -e '1d' ${WRKSRC}/tools/extra/xml_split
	@${REINPLACE_CMD} -e 's|OPENVAS_STATE_DIR|OPENVAS_LIB_INSTALL_DIR|g' ${WRKSRC}/src/manage_pg.c

post-install:
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/postgres-HOWTO ${STAGEDIR}${DOCSDIR}
	${MV} ${STAGEDIR}${ETCDIR}/openvasmd_log.conf ${STAGEDIR}${ETCDIR}/openvasmd_log.conf.sample
	${MV} ${STAGEDIR}${ETCDIR}/pwpolicy.conf ${STAGEDIR}${ETCDIR}/pwpolicy.conf.sample

.include <bsd.port.mk>
