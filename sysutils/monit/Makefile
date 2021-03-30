# Created by: Martin Pala <martinp@tildeslash.com>
# $FreeBSD$

PORTNAME=	monit
PORTVERSION=	5.28.0
CATEGORIES=	sysutils
MASTER_SITES=	https://mmonit.com/monit/dist/

MAINTAINER=	martinp@tildeslash.com
COMMENT=	Unix system management and proactive monitoring

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		bison gmake
USE_RC_SUBR=	${PORTNAME}

GNU_CONFIGURE=	yes

SUB_FILES=	pkg-message

PLIST_FILES=	bin/monit \
		etc/monitrc.sample \
		man/man1/monit.1.gz

PORTDOCS=	COPYING CHANGES

OPTIONS_DEFINE=	DOCS SSL
OPTIONS_DEFAULT=SSL

SSL_USES=		ssl
SSL_CONFIGURE_OFF=	--without-ssl

post-install:
	${INSTALL} -m 600 ${WRKSRC}/monitrc ${STAGEDIR}${PREFIX}/etc/monitrc.sample
	${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL} -m 644 ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
