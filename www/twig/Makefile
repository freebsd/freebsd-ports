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

NO_BUILD=	YES
TWIG?=		www/twig
PLIST_SUB+=	TWIG=${TWIG}
ROOTFILES=	index.php test.php goto.php
CONFFILES=	.htaccess mailfooter.inc.php3.sample
USERFILES=	announcements.inc.php3 config.inc.php3 dbconfig.inc.php3 \
		defaults.inc.php3 footer.inc.php3 header.inc.php3 \
		images.inc.php3 login.footer.inc.php3 login.form.php3 \
		login.header.inc.php3 mainmenu.inc.php3 newusergroups.inc.php3

NO_STAGE=	yes
do-install:
	-${MKDIR} ${PREFIX}/${TWIG}/config
	@(cd ${WRKSRC} && ${CP} ${ROOTFILES} ${PREFIX}/${TWIG}/ )
	@(cd ${WRKSRC} && ${CP} -R features  ${PREFIX}/${TWIG}/ )
	@(cd ${WRKSRC} && ${CP} -R images    ${PREFIX}/${TWIG}/ )
	@(cd ${WRKSRC} && ${CP} -R lib       ${PREFIX}/${TWIG}/ )
	@(cd ${WRKSRC}/config && ${CP} ${CONFFILES} ${PREFIX}/${TWIG}/config/ )
.for i in ${USERFILES}
	@${CP} ${WRKSRC}/config/${i} ${PREFIX}/${TWIG}/config/${i}-dist
	@if test ! -f ${PREFIX}/${TWIG}/config/${i} ; then \
		${CP} ${WRKSRC}/config/${i} ${PREFIX}/${TWIG}/config/${i}; \
	fi
.endfor

.include <bsd.port.mk>
