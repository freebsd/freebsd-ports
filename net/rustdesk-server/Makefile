PORTNAME=	rustdesk-server
DISTVERSION=	1.1.11-1
PORTREVISION=	2
CATEGORIES=	net

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Self hosted RustDesk server
WWW=		https://rustdesk.com/server/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	rustdesk
USE_RC_SUBR=	rustdesk-hbbr rustdesk-hbbs

USERS=		rustdesk
GROUPS=		rustdesk

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/hbbs
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/hbbr
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rustdesk-utils
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/syslog.d
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/rustdesk-server.newsyslog ${STAGEDIR}${EXAMPLESDIR}/newsyslog.sample
	${INSTALL_DATA} ${FILESDIR}/rustdesk-server.syslog ${STAGEDIR}${EXAMPLESDIR}/syslog.sample

.include <bsd.port.mk>
