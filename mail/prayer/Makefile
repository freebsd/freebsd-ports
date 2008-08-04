# New ports collection makefile for:    prayer
# Date created:         27 Dez 2003
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	prayer
PORTVERSION=	1.1.0
CATEGORIES=	mail www
MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/email/prayer/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Prayer Webmail System

BUILD_DEPENDS=	${LOCALBASE}/lib/libc-client4.a:${PORTSDIR}/mail/cclient
.if !defined(PRAYER_WITHOUT_SESSION_CACHE)
LIB_DEPENDS+=	db-4.2:${PORTSDIR}/databases/db42
.endif

USE_OPENLDAP=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_PERL5_BUILD=	yes
USE_ICONV=	yes
MAKE_ENV+=	PORTCFLAGS="${CFLAGS}"

PORTDOCS=	ACCOUNTD CMD_LINE DESIGN DONE DONE-OLD FEATURES ICONLIST \
		INSTALL LOGS NOTICE README ROADMAP SECURITY TODO URL_OPTIONS

post-extract:
	@${FIND} ${WRKSRC} -depth -type d -name CVS -exec ${RM} -rf {} \;

pre-patch:
	${CP} ${WRKSRC}/defaults/Config ${WRKSRC}/Config

do-configure:
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=" ${FILESDIR}/prayer.sh \
		> ${WRKSRC}/prayer.sh
.if defined(PRAYER_WITHOUT_SESSION_CACHE)
	${REINPLACE_CMD} \
	    -e 's|SESSION_CACHE_ENABLE = true |SESSION_CACHE_ENABLE = false|' \
	    -e 's|/usr/local/prayer|${PREFIX}/prayer|' \
		${WRKSRC}/Config
.endif

pre-install:
	if ! pw groupshow prayer; then pw groupadd prayer; fi
	if ! pw usershow prayer; then pw useradd prayer -g prayer \
		-h - -d /nonexistent -s /nonexistent -c "Prayer Webmail"; fi
	${MKDIR} ${PREFIX}/prayer
	${INSTALL_SCRIPT} ${WRKSRC}/prayer.sh \
		${LOCALBASE}/etc/rc.d/prayer.sh.sample

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
