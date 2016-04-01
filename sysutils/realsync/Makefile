# Created by: Krasimir Nachev krasi@it-sys.org
# $FreeBSD$

PORTNAME=	realsync
PORTVERSION=	0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.it-sys.org/distfiles/

MAINTAINER=	krasi@it-sys.org
COMMENT=	Parallel synchronization daemon for rsync

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	rsync:net/rsync \
		sudo:security/sudo

USES=		python
NO_BUILD=	yes

SUB_FILES=	pkg-message

PLIST_FILES=	sbin/realsync \
		etc/rc.d/realsync \
		etc/realsync.cfg.example \
		man/man8/realsync.8.gz

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/realsync ${STAGEDIR}${PREFIX}/sbin/realsync
	${INSTALL_MAN} ${WRKSRC}/man8/realsync.8 ${STAGEDIR}${PREFIX}/man/man8/realsync.8
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/realsync ${STAGEDIR}${PREFIX}/etc/rc.d/realsync
	${INSTALL_DATA} ${WRKSRC}/config/${PORTNAME}.cfg.example ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.cfg.example

.include <bsd.port.mk>
