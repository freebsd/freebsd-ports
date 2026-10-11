PORTNAME=	tarpitd
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
CATEGORIES=	mail

MAINTAINER=	przemyslaw@frasunek.com
COMMENT=	SMTP tarpit for hosts supplied by an external blocklist
WWW=		https://github.com/venglin/tarpitd

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	venglin

USE_RC_SUBR=	tarpitd

MAKE_ARGS=	NO_RCD=yes \
		WITHOUT_DEBUG_FILES=yes

PLIST_FILES=	sbin/tarpitd \
		share/man/man8/tarpitd.8.gz

OPTIONS_DEFINE=	CAPSICUM

# CAPSICUM is off by default on purpose.  It works, but capability mode
# forbids reopening /var/run/log, so if syslogd is restarted the daemon keeps
# running and silently stops logging until it is restarted itself.
CAPSICUM_DESC=		Sandbox workers with capsicum(4) (see caveat below)
CAPSICUM_MAKE_ARGS=	WITH_CAPSICUM=yes

.include <bsd.port.mk>
