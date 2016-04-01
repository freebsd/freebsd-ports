# Created by: Marc G. Fournier <scrappy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_log_sql
PORTVERSION=	1.101
PORTREVISION=	7
CATEGORIES=	www databases
MASTER_SITES=	http://www.outoforder.cc/downloads/${PORTNAME}/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-dtc

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows Apache to log to a MySQL database

OPTIONS_DEFINE=	DBI
DBI_DESC=	depend on databases/libdbi

OPTIONS_SUB=		yes
DBI_CONFIGURE_ON=	--with-dbi=${LOCALBASE}
DBI_CONFIGURE_OFF=	--without-dbi
DBI_LIB_DEPENDS=	libdbi.so:databases/libdbi

GNU_CONFIGURE=	yes
USES=		gmake tar:bzip2
USE_APACHE=	22
USE_MYSQL=	yes

CONFIGURE_ARGS+=	--with-apxs=${APXS}
LIBS+=		-L${LOCALBASE}/lib -L${LOCALBASE}/lib/mysql

post-patch:
	${REINPLACE_CMD} -e 's|@APXS_STAGE@|-S LIBEXECDIR=${STAGEDIR}${PREFIX}/${APACHEMODDIR}|' \
		${WRKSRC}/Makefile.in

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}

.include <bsd.port.mk>
