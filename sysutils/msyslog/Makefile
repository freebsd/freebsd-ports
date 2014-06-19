# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	msyslog
PORTVERSION=	1.08g
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-1.X/${PORTVERSION} \
		http://www1.corest.com/download/msyslog/
DISTNAME=	${PORTNAME}-v${PORTVERSION}-src

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Flexible and easy to integrate syslog daemon

LICENSE=	BSD4CLAUSE MIT
LICENSE_COMB=	dual

OPTIONS_DEFINE=	MYSQL PGSQL
OPTIONS_SUB=	yes
MYSQL_USE=	MYSQL=yes
MYSQL_CONFIGURE_OFF=	--without-mysql
PGSQL_USE=	PGSQL=yes
PGSQL_CONFIGURE_OFF=	--without-pgsql

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}

GNU_CONFIGURE=	yes
USES=		gmake
USE_RC_SUBR=	msyslogd
SUB_FILES=	pkg-message
USE_LDCONFIG=	yes
MANCOMPRESSED=	yes

PORTSCOUT=	skipv:1.09d

.include <bsd.port.options.mk>

.if ${OSVERSION} > 900006
EXTRA_PATCHES=	${PATCHDIR}/utmpx-src-modules-om_classic.c
.endif

post-patch:
	@${FIND} ${WRKSRC}/src/modules -name "*.c" | \
	    ${XARGS} ${REINPLACE_CMD} -e "s|typedef int socklen_t;||g"
	@${FIND} ${WRKSRC}/src/peo -name "*.h" | \
	    ${XARGS} ${REINPLACE_CMD} -e 's|"typedefs.h"|<sys/types.h>|g'
	@${FIND} ${WRKSRC}/src/ -name "*.*" | \
	    ${XARGS} ${REINPLACE_CMD} -e 's|/dev/log|/var/run/log|g' \
	    -e "s|/etc/syslog.conf|${PREFIX}/etc/syslog.conf|g"
	@${FIND} ${WRKSRC}/src/ -name "*.bak" -delete
	@${REINPLACE_CMD} -e 's|@prefix@|${STAGEDIR}${PREFIX}|g' \
		${WRKSRC}/src/modules/Makefile.in \
		${WRKSRC}/src/peo/Makefile.in \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|@mandir@|${STAGEDIR}${PREFIX}/man|g' \
		${WRKSRC}/src/man/GNUmakefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
