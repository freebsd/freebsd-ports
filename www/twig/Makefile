# $FreeBSD$

PORTNAME=	twig
PORTVERSION=	2.8.3
PORTREVISION=	2
CATEGORIES=	www mail
MASTER_SITES=	ftp://ftp.dinoex.de/pub/FreeBSD/distfiles/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Web Based Email Client and Scheduler

.if !defined(WITHOUT_PHP_DEPENDS)
USE_PHP=	ctype imap openssl pgsql pcre posix session tokenizer xml zlib
.endif

NO_BUILD=	yes

TWIG?=		www/twig
PLIST_SUB+=	TWIG=${TWIG}
ROOTFILES=	index.php test.php goto.php
CONFFILES=	.htaccess mailfooter.inc.php3.sample
USERFILES=	announcements.inc.php3 config.inc.php3 dbconfig.inc.php3 \
		defaults.inc.php3 footer.inc.php3 header.inc.php3 \
		images.inc.php3 login.footer.inc.php3 login.form.php3 \
		login.header.inc.php3 mainmenu.inc.php3 newusergroups.inc.php3

do-install:
	-${MKDIR} ${STAGEDIR}${PREFIX}/${TWIG}/config
	@(cd ${WRKSRC} && ${CP} ${ROOTFILES} ${STAGEDIR}${PREFIX}/${TWIG}/ )
	@(cd ${WRKSRC} && ${CP} -R features  ${STAGEDIR}${PREFIX}/${TWIG}/ )
	@(cd ${WRKSRC} && ${CP} -R images    ${STAGEDIR}${PREFIX}/${TWIG}/ )
	@(cd ${WRKSRC} && ${CP} -R lib       ${STAGEDIR}${PREFIX}/${TWIG}/ )
	@(cd ${WRKSRC}/config && ${CP} ${CONFFILES} ${STAGEDIR}${PREFIX}/${TWIG}/config/ )
.for i in ${USERFILES}
	@${CP} ${WRKSRC}/config/${i} ${STAGEDIR}${PREFIX}/${TWIG}/config/${i}-dist
.endfor

.include <bsd.port.mk>
