# Created by: Fabian Keil <fk@fabiankeil.de>
# $FreeBSD$

PORTNAME=	zsd
PORTVERSION=	0.0.2014.12.07
CATEGORIES=	sysutils
MASTER_SITES=	http://www.fabiankeil.de/sourcecode/zfs-snapshot-destroyer/
DISTNAME=	${PORTNAME}-2014-12-07-c2d3662

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Destroys ZFS snapshots

LICENSE=	MIT

PORTSCOUT=	ignore:1

USES=		perl5 shebangfix
SHEBANG_FILES=	zsd
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	sbin/zsd \
		man/man8/zsd.8.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zsd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/zsd.8 ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
