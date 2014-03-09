# Created by: Marc G. Fournier <scrappy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_log_sql
PORTVERSION=	1.101
PORTREVISION=	6
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
DBI_LIB_DEPENDS=	libdbi.so:${PORTSDIR}/databases/libdbi

LATEST_LINK=	mod_log_sql2-dtc
GNU_CONFIGURE=	yes
USES=		gmake
USE_BZIP2=	yes
USE_APACHE=	22
USE_MYSQL=	yes

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--with-apxs=${APXS}
CONFIGURE_ENV+=		LIBS="-L${LOCALBASE}/lib -L${LOCALBASE}/lib/mysql"

post-patch:
	${REINPLACE_CMD} -e 's|@APXS_STAGE@|-S LIBEXECDIR=${STAGEDIR}${PREFIX}/${APACHEMODDIR}|' \
		${WRKSRC}/Makefile.in

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}

.include <bsd.port.post.mk>
