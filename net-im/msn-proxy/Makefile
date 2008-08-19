# New ports collection makefile for:	msn-proxy
# Date created:			20 January 2008
# Whom:				Luiz Otavio O Souza <loos.br@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	msn-proxy
PORTVERSION=	0.6.2
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	loos.br@gmail.com
COMMENT=	Messenger proxy/control daemon

LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent

OPTIONS+=	MYSQL		"Use MySQL database version" off
OPTIONS+=	PGSQL		"Use Postgresql (pgsql) database version" on

WRKSRC=		${WRKDIR}/${PORTNAME}

DOCS=		INSTALL
MSNPROXYWWW=	ajax.inc.php al.inc.php bl.inc.php chat-to.php chat.php \
		conf.php default.array.cmd.inc.php default.array.option.inc.php \
		default.array.status.inc.php fl.inc.php group.inc.php \
		header.inc.php index.php save_contact_op.php save_default_op.php \
		save_msg.php save_user_op.php user.php view-to.php view.php \
		user.inc.php
MSNPROXYIMG=	ausente.gif block.gif notinlist.png ocupado.gif offline.gif \
		online.gif send_im.gif webcam.png

WANT_PHP_WEB=	yes
USE_PHP=	session sockets
MAKE_ARGS=	SYSCONFDIR=$(DESTDIR)${PREFIX}/etc/msn-proxy \
		BINDIR=$(DESTDIR)${PREFIX}/bin

.include <bsd.port.pre.mk>

.if defined(WITH_PGSQL)
DISTVERSIONSUFFIX=	-pgsql
MSNPROXYWWW+=		pgsql.inc.php
SUB_FILES=		pkg-message-pgsql
USE_PGSQL=		yes
USE_PHP+=		pgsql
PLIST_SUB+=		PGSQL=""
.else
PLIST_SUB+=		PGSQL="@comment "
.endif

.if defined(WITH_MYSQL)
DISTVERSIONSUFFIX=	-mysql
MSNPROXYWWW+=		mysql.inc.php
SUB_FILES=		pkg-message-mysql
USE_MYSQL=		yes
USE_PHP+=		mysql
PLIST_SUB+=		MYSQL=""
.else
PLIST_SUB+=		MYSQL="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/config.h

post-install:
	@${MKDIR} ${WWWDIR}
.for FILE in ${MSNPROXYWWW}
	@cd ${WRKSRC}/php && ${INSTALL} -m 644 ${FILE} ${WWWDIR}
.endfor
	@${MKDIR} ${WWWDIR}/imagens
.for FILE in ${MSNPROXYIMG}
	@cd ${WRKSRC}/php/imagens && ${INSTALL} -m 644 ${FILE} ${WWWDIR}/imagens
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}/${FILE}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
