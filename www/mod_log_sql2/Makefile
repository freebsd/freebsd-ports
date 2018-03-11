# Created by: Clement Laforet <clement@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_log_sql
PORTVERSION=	1.101
PORTREVISION=	6
CATEGORIES=	www databases
MASTER_SITES=	http://www.outoforder.cc/downloads/${PORTNAME}/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows Apache to log to a MySQL database

USES=		apache:2.2+ gmake tar:bzip2
USE_MYSQL=	yes
GNU_CONFIGURE=	yes

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	DBI DOCS

DBI_CONFIGURE_WITH=	dbi=${LOCALBASE}
DBI_LIB_DEPENDS=	libdbi.so:databases/libdbi

DBI_DESC=	depend on databases/libdbi
PORTDOCS=	manual.html manual.xml

.include <bsd.port.options.mk>

APMODCFG=	330_mod_log_sql.conf.sample
SUB_FILES+=	${APMODCFG} pkg-message
SUB_LIST+=	APMODCFG=${APMODCFG:C/.sample//}
PLIST_SUB+=	APMODCFG=${APMODCFG}

CONFIGURE_ARGS+=--with-apxs=${APXS}
LIBS+=		-L${LOCALBASE}/lib -L${LOCALBASE}/lib/mysql

post-patch:
	${REINPLACE_CMD} -e 's|@APXS_STAGE@|-S LIBEXECDIR=${STAGEDIR}${PREFIX}/${APACHEMODDIR}|' \
		${WRKSRC}/Makefile.in

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d
	${CP} ${WRKDIR}/${APMODCFG} ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/*.so
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
