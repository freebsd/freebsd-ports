# New ports collection makefile for:	barnyard2
# Date created:				28 Aug 2009
# Whom:					pauls
#
# $FreeBSD$
#

PORTNAME=	barnyard2
PORTVERSION=	1.9
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.securixlive.com/download/barnyard2/

MAINTAINER=	pauls@utdallas.edu
COMMENT=	An output system for Snort or Suricata that parses unified2 files

OPTIONS=	MYSQL "Enable MySQL support" on \
		POSTGRESQL "Enable PostgreSQL support" off \
		SNORT "Depend on security/snort" off \
		SURICATA "Depend on security/suricata" off
.if !defined(SLAVE)
OPTIONS+=	TCL "Enable TCL support" off
.endif

USE_RC_SUBR=	barnyard2
GNU_CONFIGURE=	yes
SUB_FILES=	pkg-message

PORTDOCS1=	README
PORTDOCS2=	INSTALL README.aruba README.database README.sguil
PORTDOCS=	${PORTDOCS1} ${PORTDOCS2}

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql \
			--with-mysql-includes=${LOCALBASE}/include/mysql \
			--with-mysql-libraries=${LOCALBASE}/lib/mysql
SUB_LIST+=		MYSQL=" mysql"
.else
SUB_LIST+=		MYSQL=""
.endif

.if defined(WITH_POSTGRESQL)
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-postgresql
SUB_LIST+=		PGSQL=" postgresql"
.else
SUB_LIST+=		PGSQL=""
.endif

.if defined(WITH_SNORT)
RUN_DEPENDS+=		${LOCALBASE}/bin/snort:${PORTSDIR}/security/snort
.endif

.if defined(WITH_SURICATA)
RUN_DEPENDS+=		${LOCALBASE}/bin/suricata:${PORTSDIR}/security/suricata
.endif

.if defined(WITH_TCL)
USE_TCL=		yes
CONFIGURE_ARGS+=	--with-tcl=${PREFIX}/lib/tcl8.4
LIB_DEPENDS+=		tcl84.1:${PORTSDIR}/lang/tcl84
.endif

pre-install:
	${CHMOD} 744 ${WRKSRC}/install-sh

post-patch:
	@${REINPLACE_CMD} 's|/etc|${LOCALBASE}/etc|' \
		${WRKSRC}/etc/barnyard2.conf

post-install:

.for f in barnyard2.conf
	[ -f ${PREFIX}/etc/${f} ] || \
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${PREFIX}/etc/${f}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS1} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS2} ${DOCSDIR}
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
