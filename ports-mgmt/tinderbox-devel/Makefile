# Ports collection makefile for:	misc/tinderbox
# Whom:			Edwin Groothuis <edwin@mavetju.org>
# Date created:		31 december 2005
#
# $FreeBSD$

PORTNAME=	tinderbox
PORTVERSION=	2.3.0
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://tinderbox.marcuscom.com/

MAINTAINER=	andreas@syndrom23.de
COMMENT=	Port build tinderbox system

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/Net/SMTP.pm:${PORTSDIR}/net/p5-Net \
		${LOCALBASE}/share/pear/DB.php:${PORTSDIR}/databases/pear-DB \
		cvsup:${PORTSDIR}/net/cvsup-without-gui

OPTIONS=	PGSQL "With pgsql" On \
		MYSQL "With mysql" Off

NO_BUILD=	yes
USE_APACHE=	1.3+
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

.if defined(WITHOUT_PGSQL) && defined(WITHOUT_MYSQL)
BROKEN=	Tinderbox is useless without a database. Please (re)run 'make config' and choose one of PGSQL and MYSQL
.endif

USE_PHP=	session

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
USE_PHP+=	pgsql
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
.endif

.if defined(WITH_MYSQL)
USE_PHP+=	mysql
USE_MYSQL=	yes
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql${MYSQL_VER}
.endif

.include "${PORTSDIR}/Mk/bsd.php.mk"

post-extract:
.for f in inc_ds.php inc_tinderbox.php
	${MV} ${WRKSRC}/www-exp/${f} ${WRKSRC}/www-exp/${f}-dist
.endfor

post-patch:
.if defined(WITH_MYSQL)
	${REINPLACE_CMD} \
		-e 's,DB_MAN_PREREQS=.*,DB_MAN_PREREQS="databases/p5-DBD-mysql${MYSQL_VER} databases/mysql${MYSQL_VER}-client",' \
		${WRKSRC}/lib/setup-mysql.sh
.endif

do-install:
	${MKDIR} ${PREFIX}/tinderbox/scripts
	${CP} -R ${WRKSRC}/* ${PREFIX}/tinderbox/scripts

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
