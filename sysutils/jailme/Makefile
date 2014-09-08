# Created by: wmoran
# $FreeBSD$

PORTNAME=	jailme
PORTVERSION=	0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://people.collaborativefusion.com/~wmoran/code/jailme/

MAINTAINER=	wmoran@collaborativefusion.com
COMMENT=	setuid version of jexec to allow normal users access to jails

PLIST_FILES=	"@(,,4751) sbin/jailme"

USES=		tar:bzip2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jailme ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
