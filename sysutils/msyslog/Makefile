# New ports collection makefile for:	msyslog
# Date created:				14 May 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	msyslog
PORTVERSION=	1.08g
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-1.X/${PORTVERSION} \
		http://www1.corest.com/download/msyslog/
DISTNAME=	${PORTNAME}-v${PORTVERSION}-src

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Flexible and easy to integrate syslog daemon

OPTIONS=	MYSQL	"With MySQL Support"	off \
		PGSQL	"With Postgres Support"	off \

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_RC_SUBR=	msyslogd
PKGMESSAGE=	${WRKDIR}/pkg-message
USE_LDCONFIG=	yes
MANCOMPRESSED=	yes

PORTSCOUT=	skipv:1.09d

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900006
EXTRA_PATCHES=	${PATCHDIR}/utmpx-src-modules-om_classic.c
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
MAN8+=	om_mysql.8
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
MAN8+=	om_pgsql.8
.else
CONFIGURE_ARGS+=	--without-pgsql
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

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/examples/* ${EXAMPLESDIR}
	@${CAT} ${PKGDIR}/pkg-message | ${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
	    > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
