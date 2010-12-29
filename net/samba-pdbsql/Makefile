# New ports collection makefile for:	samba-pdbsql
# Date created:				28th Aug 2006
# Whom:					Timur I. Bakeyev <timur@gnu.org>
#
# $FreeBSD$
#

PORTNAME=		pdbsql
PORTVERSION=		34
CATEGORIES=		net
MASTER_SITES=		SF/${PORTNAME}/${PORTNAME}_${PORTVERSION}/
PKGNAMEPREFIX=		samba-

MAINTAINER=		timur@FreeBSD.org
COMMENT=		Multiplexor, MySQL and PostgeSQL passdb backends for Samba3

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
# Add a build dependency for Samba port
USE_AUTOTOOLS=		autoconf autoheader

SAMBA_PORT?=		net/samba34

OPTIONS=		MYSQL	"With MySQL passdb backend"		on \
			PGSQL	"With PostgreSQL passdb backend"	on

.include <bsd.port.pre.mk>

SAMBA_WRKSRC!=		cd ${PORTSDIR}/${SAMBA_PORT} && ${MAKE} -V WRKSRC
.if !defined(SAMBA_WRKSRC) || empty(SAMBA_WRKSRC)
IGNORE=			unable to determine SAMBA_WRKSRC directory. Cannot continue
.endif
SAMBA_MODULEDIR!=	cd ${PORTSDIR}/${SAMBA_PORT} && ${MAKE} -V SAMBA_MODULEDIR
.if !defined(SAMBA_MODULEDIR) || empty(SAMBA_MODULEDIR)
SAMBA_MODULEDIR=	${PREFIX}/lib/samba
.endif
SAMBA_PDBDIR=		${SAMBA_MODULEDIR}/pdb

BUILD_DEPENDS+=		${NONEXISTENT}:${PORTSDIR}/${SAMBA_PORT}:configure

CONFIGURE_ARGS+=	--libdir=${SAMBA_PDBDIR} \
			--with-samba-dir=${SAMBA_WRKSRC}

PLIST_SUB+=		SAMBA_PDBDIR=${SAMBA_PDBDIR:S/${PREFIX}\///} \
			SAMBA_MODULEDIR=${SAMBA_MODULEDIR:S/${PREFIX}\///}

.if exists(${LOCALBASE}/bin/mysql)
WITH_MYSQL=		yes
.	undef		WITHOUT_MYSQL
.endif

.if exists(${LOCALBASE}/bin/pg_config)
WITH_PGSQL=		yes
.	undef		WITHOUT_PGSQL
.endif

.if !defined(WITHOUT_MYSQL)
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql-prefix=${LOCALBASE}
PLIST_SUB+=		MYSQL=""
.else
PLIST_SUB+=		MYSQL="@comment "
.endif

.if !defined(WITHOUT_PGSQL)
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-pgsql-prefix=${LOCALBASE}
PLIST_SUB+=		PGSQL=""
.else
PLIST_SUB+=		PGSQL="@comment "
.endif

pre-configure:
			cd ${SAMBA_WRKSRC} && ${MAKE} proto

do-install:
			@${MKDIR} ${EXAMPLESDIR}
			@${MKDIR} ${SAMBA_PDBDIR}
			${INSTALL_PROGRAM} ${WRKSRC}/multi.so ${SAMBA_PDBDIR}
.if !defined(WITHOUT_MYSQL)
			${INSTALL_PROGRAM} ${WRKSRC}/mysql.so ${SAMBA_PDBDIR}
.	for f in mysql.dump smb.conf.mysql
			${INSTALL_DATA} ${WRKSRC}/docs/${f} ${EXAMPLESDIR}
.	endfor
.endif
.if !defined(WITHOUT_PGSQL)
			${INSTALL_PROGRAM} ${WRKSRC}/pgsql.so ${SAMBA_PDBDIR}
.	for f in pgsql.dump smb.conf.pgsql
			${INSTALL_DATA} ${WRKSRC}/docs/${f} ${EXAMPLESDIR}
.	endfor
.endif

.include <bsd.port.post.mk>
