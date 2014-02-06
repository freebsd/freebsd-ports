# Created by: Fabian Keil <fk@fabiankeil.de>
# $FreeBSD$

PORTNAME=	zsd
PORTVERSION=	0.0.2013.10.08
CATEGORIES=	sysutils
MASTER_SITES=	http://www.fabiankeil.de/sourcecode/zfs-snapshot-destroyer/
DISTNAME=	${PORTNAME}-2013-10-08-f7cd2b3

MAINTAINER=	fk@fabiankeil.de
COMMENT=	Destroys ZFS snapshots

PLIST_FILES=	sbin/zsd \
		man/man8/zsd.8.gz

PORTSCOUT=	ignore:1

USES=		perl5 shebangfix
SHEBANG_FILES=	zsd
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zsd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/zsd.8 ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
