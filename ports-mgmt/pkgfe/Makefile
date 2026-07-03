PORTNAME=	pkgfe
DISTVERSION=	20260704
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://ketas.si.pri.ee/pkgfe/releases/

MAINTAINER=	bugs-freebsd-org916@ketas.si.pri.ee
COMMENT=	Ncurses frontend for ports collection
WWW=		http://ketas.si.pri.ee/pkgfe/

LICENSE=	BSD2CLAUSE

USES=		tar:txz

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	sbin/pkgfe \
		etc/pkgfe.conf.sample \
		share/man/man8/pkgfe.8.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkgfe ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/pkgfe.conf.sample ${STAGEDIR}${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/pkgfe.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
