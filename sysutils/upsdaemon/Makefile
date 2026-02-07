PORTNAME=	upsdaemon
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://BSDforge.com/projects/sysutils/upsdaemon/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Simple APC UPS Daemon
WWW=		https://BSDforge.com/projects/sysutils/upsdaemon/

LICENSE=	BSD2CLAUSE

USE_RC_SUBR=	upsdaemon

post-patch:
	@${REINPLACE_CMD} "s,/man/man8,/share/man/man8,g" \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
