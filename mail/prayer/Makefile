# New ports collection makefile for:    prayer
# Date created:         27 Dez 2003
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	prayer
PORTVERSION=	1.0.8
PORTREVISION=	1
CATEGORIES=	mail www
MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/email/prayer/
# ftp://ftp.csx.cam.ac.uk/pub/software/email/prayer/prayer-1.0.8.tar.gz

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Prayer Webmail System

BUILD_DEPENDS=	${LOCALBASE}/lib/libc-client4.a:${PORTSDIR}/mail/cclient
.if !defined(PRAYER_WITHOUT_SESSION_CACHE)
LIB_DEPENDS+=	${BERKLEYDB_LIB}:${PORTSDIR}/${BERKLEYDB_PORT}
.endif

USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_REINPLACE=	yes
USE_PERL5_BUILD=	yes
MAKE_ENV+=	PORTCFLAGS="${CFLAGS}"
BERKLEYDB_PORT?=	databases/db3
BERKLEYDB_LIB?=		db3.3

DOCS=	ACCOUNTD CMD_LINE DESIGN DONE DONE-OLD FEATURES ICONLIST \
	INSTALL LOGS NOTICE README ROADMAP SECURITY TODO URL_OPTIONS

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
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${i} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
