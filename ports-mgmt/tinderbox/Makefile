# Ports collection makefile for:	misc/tinderbox
# Whom:			Edwin Groothuis <edwin@mavetju.org>
# Date created:		31 december 2005
#
# $FreeBSD$

PORTNAME=	tinderbox
PORTVERSION=	2.3.2
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://tinderbox.marcuscom.com/

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Port build tinderbox system

RUN_DEPENDS=	${LOCALBASE}/share/pear/DB.php:${PORTSDIR}/databases/pear-DB \

OPTIONS=	PGSQL "With pgsql" Off \
		MYSQL "With mysql" On \
		CSUP  "Use csup for updates" On \
		CVSUP "Use cvsup for updates" Off

NO_BUILD=	yes
USE_APACHE=	1.3+
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

MAN1=		tc-configCcache.1 tc-configDistfile.1 tc-configGet.1 \
		tc-configJail.1 tc-configTinderd.1 tc-init.1

.include <bsd.port.pre.mk>

.if defined(WITHOUT_PGSQL) && defined(WITHOUT_MYSQL)
IGNORE=	is useless without a database. Please (re)run 'make config' and choose one of PGSQL and MYSQL
.endif

USE_PHP=	session

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
USE_PHP+=	pgsql
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
.endif

.if !defined(WITHOUT_MYSQL)
USE_PHP+=	mysql
USE_MYSQL=	yes
IGNORE_WITH_MYSQL=	323 40
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql${MYSQL_VER:S/323//}
.endif

.if ! (${OSVERSION} > 700014 || ( ${OSVERSION} >= 601101 && ${OSVERSION} < 700000 ))
.if !defined(WITHOUT_CSUP)
RUN_DEPENDS+=	csup:${PORTSDIR}/net/csup
.endif
.endif

.if defined(WITH_CVSUP)
RUN_DEPENDS+=	cvsup:${PORTSDIR}/net/cvsup-without-gui
.endif

.include "${PORTSDIR}/Mk/bsd.php.mk"

post-extract:
.for f in inc_ds.php inc_tinderbox.php
	${MV} ${WRKSRC}/www-exp/${f} ${WRKSRC}/www-exp/${f}-dist
.endfor

post-patch:
.if defined(WITH_MYSQL)
	@${REINPLACE_CMD} \
		-e 's,DB_MAN_PREREQS=.*,DB_MAN_PREREQS="databases/p5-DBD-mysql${MYSQL_VER} databases/mysql${MYSQL_VER}-client",' \
		${WRKSRC}/lib/setup-mysql.sh
	@${RM} ${WRKSRC}/lib/setup-mysql.sh.bak
.endif
	@${RM} ${WRKSRC}/create.orig ${WRKSRC}/setup.sh.orig

do-install:
	${MKDIR} ${PREFIX}/tinderbox/scripts
	${CP} -R ${WRKSRC}/* ${PREFIX}/tinderbox/scripts

post-install:
	cd ${WRKSRC}/man/man1 && ${INSTALL_MAN} ${MAN1} ${MAN1PREFIX}/man/man1
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
