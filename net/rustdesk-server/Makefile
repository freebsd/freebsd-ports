PORTNAME=	rustdesk-server
DISTVERSION=	1.1.14
PORTREVISION=	6
CATEGORIES=	net

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Self hosted RustDesk server
WWW=		https://rustdesk.com/server/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	rustdesk
GH_PROJECT=	hbb_common:common
GH_SUBDIR=	libs/hbb_common:common
GH_TAGNAME=	49c6b24:common
USE_RC_SUBR=	rustdesk-hbbr rustdesk-hbbs

USERS=		rustdesk
GROUPS=		rustdesk

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/syslog.d
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/rustdesk-server.newsyslog ${STAGEDIR}${EXAMPLESDIR}/newsyslog.sample
	${INSTALL_DATA} ${FILESDIR}/rustdesk-server.syslog ${STAGEDIR}${EXAMPLESDIR}/syslog.sample

.include <bsd.port.mk>
