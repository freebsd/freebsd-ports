# Created by: Martin Pala <martinp@tildeslash.com>
# $FreeBSD$

PORTNAME=	monit
PORTVERSION=	5.6
CATEGORIES=	sysutils
MASTER_SITES=	http://www.mmonit.com/monit/dist/

MAINTAINER=	martinp@tildeslash.com
COMMENT=	Unix system management and proactive monitoring

MAN1=	monit.1

GNU_CONFIGURE=	yes
USES=	bison
USE_GMAKE=	yes
USE_RC_SUBR=	${PORTNAME}

CONFIGURE_ENV=	CONFIG_SHELL="${SH}" \
		LOCALBASE="${LOCALBASE}"

OPTIONS_DEFINE=	SSL
OPTIONS_DEFAULT=	SSL

PLIST_FILES=	bin/monit \
		etc/monitrc.sample

SUB_FILES=	pkg-message

PORTDOCS=	CHANGES COPYING README

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MSSL}
CONFIGURE_ARGS+=	--without-ssl
.endif

post-install:
	${INSTALL} -m 600 ${WRKSRC}/monitrc ${PREFIX}/etc/monitrc.sample
.if ${PORT_OPTIONS:MDOCS}
	${INSTALL} -d ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL} -m 644 ${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
