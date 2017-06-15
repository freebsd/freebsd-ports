# Created by: Raul Pollicino <email-freebsd@def-defying.com>
# $FreeBSD$

PORTNAME=	squirrelmail-tmda-plugin
PORTVERSION=	1.0.2
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.squirrelmail.org/plugins/
DISTNAME=	tmdatools 1.0.2 1.4.2 \(stable\)
DISTFILES=	tmdatools.1.0.2-1.4.2.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Adds TMDA support to SquirrelMail

RUN_DEPENDS=	tmda-filter:mail/tmda \
		${SQUIRRELDIR:S,^${PREFIX}/,${LOCALBASE}/,}/index.php:mail/squirrelmail

USES=		perl5
NO_BUILD=	yes
NO_ARCH=	yes

SQUIRREL_PLUGIN_NAME=	tmdatools
WRKSRC=		${WRKDIR}/tmdatools

.ifndef WITHOUT_WWWDIR
SQUIRRELDIR?=	${PREFIX}/www/squirrelmail
PLIST_SUB+=	SQUIRRELDIR=www/squirrelmail
.else
SQUIRRELDIR?=	${PREFIX}/squirrelmail
PLIST_SUB+=	SQUIRRELDIR=squirrelmail
.endif
TMDATOOLDIR?=	${SQUIRRELDIR}/plugins/${SQUIRREL_PLUGIN_NAME}
PLIST_SUB+=	TMDATOOLDIR=plugins/${SQUIRREL_PLUGIN_NAME}
SUB_LIST=	TMDATOOLDIR=${TMDATOOLDIR}
SUB_FILES=	pkg-message

pre-everything::
	@${ECHO} "The plugin expects SquirrelMail install in ${SQUIRRELDIR}"
	@${ECHO} "To use the old location ${PREFIX}/squirrelmail define WITHOUT_WWWDIR=yes"
	@${ECHO} ""

post-patch:
	@${REINPLACE_CMD} \
		-e 's|"/usr/local/tmda-1.0.2/"|${TMDATOOLDIR}|g' \
		${WRKSRC}/tmdatools_config.php.sample
	@${RM} ${WRKSRC}/tmdatools_config.php.sample.bak

do-install:
	${MKDIR} ${STAGEDIR}${TMDATOOLDIR}
	${CP} -Rp ${WRKSRC}/ ${STAGEDIR}${TMDATOOLDIR}

.include <bsd.port.mk>
