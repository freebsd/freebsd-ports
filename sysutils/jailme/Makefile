# Created by: wmoran
# $FreeBSD$

PORTNAME=	jailme
PORTVERSION=	0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://people.collaborativefusion.com/~wmoran/code/jailme/

MAINTAINER=	wmoran@collaborativefusion.com
COMMENT=	setuid version of jexec to allow normal users access to jails

PLIST_FILES=	sbin/jailme

USES=		tar:bzip2

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${STAGEDIR}${PREFIX}|' \
		${WRKSRC}/${MAKEFILE}

.include <bsd.port.mk>
