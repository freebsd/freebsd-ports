# Created by: Martin Pala <martinp@tildeslash.com>
# $FreeBSD$

PORTNAME=	monit
PORTVERSION=	5.7
CATEGORIES=	sysutils
MASTER_SITES=	http://www.mmonit.com/monit/dist/

MAINTAINER=	martinp@tildeslash.com
COMMENT=	Unix system management and proactive monitoring

LICENSE=	GPLV3
LICENSE_FILE=	COPYING

GNU_CONFIGURE=	yes
USES=	bison gmake
USE_RC_SUBR=	${PORTNAME}

CONFIGURE_ENV=	CONFIG_SHELL="${SH}" \
		LOCALBASE="${LOCALBASE}"

OPTIONS_DEFINE=	SSL
OPTIONS_DEFAULT=	SSL

PLIST_FILES=	bin/monit \
		etc/monitrc.sample \
		man/man1/monit.1.gz

SUB_FILES=	pkg-message

PORTDOCS=	CHANGES COPYING README

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MSSL}
CONFIGURE_ARGS+=	--without-ssl
.endif

post-install:
	${INSTALL} -m 600 ${WRKSRC}/monitrc ${STAGEDIR}${PREFIX}/etc/monitrc.sample
.if ${PORT_OPTIONS:MDOCS}
	${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL} -m 644 ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
