# New ports collection makefile for:	gatekeeper
# Date created:		Wed Apr 15 15:41:00 GMT 2000
# Whom:			Roger Hardiman <roger@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gatekeeper
#PORTVERSION=	2.2.8
DISTVERSION=	2.2.8
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	SF/openh323gk/Sources/${PORTVERSION}
DISTNAME=	gnugk-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GnuGK is GPL Gate Keeper for OhPhone, GnomeMeeting, NetMeeting, and H323

LIB_DEPENDS=	h323_r.1:${PORTSDIR}/net/openh323

#WRKSRC=		${WRKDIR}/${MASTER_SITE_SUBDIR}-${DISTVERSION:C/-[0-9]$//}

USE_RC_SUBR=	gnugk
USERS=		gnugk
GROUPS=		${USERS}

USE_AUTOTOOLS=	autoconf
CONFIGURE_ARGS+=	--disable-firebird

USE_GMAKE=	yes
ALL_TARGET=	optshared addpasswd
MAKE_ENV=	PWLIBDIR=${LOCALBASE}/share/pwlib \
		OPENH323DIR=${LOCALBASE}/share/openh323 \
		SYSLIBDIR=${LOCALBASE}/lib
MAKE_ARGS=	OSTYPE=${OPSYS} MACHTYPE=${ARCH:S/i386/x86/} \
		OSRELEASE=${OSVERSION} CPLUS=${CXX}

PLIST_SUB=	PORTNAME=${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/openh323
EXAMPLESDIR=	${PREFIX}/share/examples/openh323

.include <bsd.port.pre.mk>

.if defined(WITH_FDSET)
CONFIGURE_ARGS+=	--with-large-fdset=${WITH_FDSET}
.endif

.if defined(WITH_RADIUS)
CONFIGURE_ARGS+=	--enable-radius
.else
CONFIGURE_ARGS+=	--disable-radius
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--enable-mysql \
			--with-mysql-dir=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--disable-mysql
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--enable-pgsql
.else
CONFIGURE_ARGS+=	--disable-pgsql
.endif

pre-everything::
.if !defined(WITH_RADIUS) || !defined(WITH_MYSQL) || !defined(WITH_PGSQL) || !defined(WITH_FDSET)
	@${ECHO_MSG} "Additional build options are:"
	@${ECHO_MSG} ""
.endif
.ifndef(WITH_RADIUS)
	@${ECHO_MSG} "WITH_RADIUS=yes - enable Radius support"
	@${ECHO_MSG} ""
.endif
.ifndef(WITH_MYSQL)
	@${ECHO_MSG} "WITH_MYSQL=yes - enable the MySQL backend"
	@${ECHO_MSG} ""
.endif
.ifndef(WITH_PGSQL)
	@${ECHO_MSG} "WITH_PGSQL=yes - enable the PostgreSQL backend"
	@${ECHO_MSG} ""
.endif
.ifndef(WITH_FDSET)
	@${ECHO_MSG} "WITH_FDSET=<some number> - expand the 'Maximum number of sockets'"
	@${ECHO_MSG} "Default is: 1024"
	@${ECHO_MSG} ""
.endif

pre-su-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
	    ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/obj_r/gnugk ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/obj_r/addpasswd ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/etc/complete.ini ${PREFIX}/etc/gnugk.ini.default
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/${PORTNAME}
	@${CP} -Rp ${WRKSRC}/docs/*.txt ${DOCSDIR}/${PORTNAME}
.endif
	@${MKDIR} ${EXAMPLESDIR}/${PORTNAME}
	@${CP} -Rp ${WRKSRC}/etc/*.ini ${EXAMPLESDIR}/${PORTNAME}

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
	    ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
