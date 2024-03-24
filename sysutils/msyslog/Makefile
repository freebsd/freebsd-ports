PORTNAME=	msyslog
DISTVERSION=	1.08g
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-1.X/${DISTVERSION}
DISTNAME=	${PORTNAME}-v${DISTVERSION}-src

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Flexible and easy to integrate syslog daemon
WWW=		https://sourceforge.net/projects/msyslog/

LICENSE=	BSD4CLAUSE MIT
LICENSE_COMB=	dual

DEPRECATED=	Unmaintained and last upstream release in 2003
EXPIRATION_DATE=2024-04-13

USES=		gmake
USE_LDCONFIG=	yes
USE_RC_SUBR=	msyslogd

GNU_CONFIGURE=	yes

PORTSCOUT=	skipv:1.09a,1.09b,1.09c,1.09d
SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}

OPTIONS_DEFINE=	MYSQL PGSQL EXAMPLES
OPTIONS_SUB=	yes

MYSQL_USES=	mysql
MYSQL_CONFIGURE_OFF=	--without-mysql
PGSQL_USES=	pgsql
PGSQL_CONFIGURE_OFF=	--without-pgsql

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
	@${REINPLACE_CMD} -e 's|@mandir@|${STAGEDIR}${PREFIX}/share/man|g' \
		${WRKSRC}/src/man/GNUmakefile.in

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
