# New ports collection makefile for:	audit
# Date created:				24 March 2002
# Whom:					anders
#
# $FreeBSD$
#

PORTNAME=	audit
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.corest.com/download/audit/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/
DISTNAME=	${PORTNAME}-v${PORTVERSION}beta-src

MAINTAINER=	anders@FreeBSD.org
COMMENT=	Tools for remote and centralized audit data collection

.if defined(WITH_MYSQL)
LIB_DEPENDS+=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
.endif
.if defined(WITH_PGSQL)
POSTGRESQL_PORT?=	databases/postgresql7
LIB_DEPENDS+=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-v${PORTVERSION}beta

USE_GMAKE=	yes
USE_REINPLACE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-audit-libdir=${PREFIX}/lib/alat
.if defined(WITH_MYSQL)
CONFIGURE_ARGS+=	--with-mysql \
			--with-mysql-libdir=${LOCALBASE}/lib/mysql \
			--with-mysql-incdir=${LOCALBASE}/include
PLIST_SUB+=	MYSQL=''
.else
PLIST_SUB+=	MYSQL='@comment '
.endif
.if defined(WITH_PGSQL)
CONFIGURE_ARGS+=	--with-pgsql \
			--with-pgsql-libdir=${LOCALBASE}/lib \
			--with-pgsql-incdir=${LOCALBASE}/include
PLIST_SUB+=	PGSQL=''
.else
PLIST_SUB+=	PGSQL='@comment '
.endif
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/alat
MANCOMPRESSED=	yes
MAN1=	audit.1
MAN8=	auditd.8

DOCS=	COPYING README TODO
FIXPREFIX_CONF=	src/include/audconf.h src/auditd/auditd.8
LIBVERSION=	1

post-patch:
	${REINPLACE_CMD} -e "s@Linux@FreeBSD@g" ${WRKSRC}/configure
	(${FIND} ${WRKSRC}/src/modules -name Makefile.in -exec \
		${REINPLACE_CMD} -e \
		"s!^LIB=\(.*\).{VERSION}!LIB=\1${LIBVERSION}!" {} \;)
	${REINPLACE_CMD} -e "s@AUDIT_VERSION@\"${LIBVERSION}\"@g" \
		${WRKSRC}/src/lib/modules.c
.for f in ${FIXPREFIX_CONF}
	${REINPLACE_CMD} -e "s@/etc/auditd.conf@${PREFIX}/etc/auditd.conf@g" \
		${WRKSRC}/${f}
.endfor

post-install:
	${INSTALL_DATA}	${WRKSRC}/auditd.conf ${PREFIX}/etc/auditd.conf.sample
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
