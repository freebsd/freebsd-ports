# Created by: Marin Atanasov <dnaeon@gmail.com>
# $FreeBSD$

PORTNAME=	pkg_add_it
PORTVERSION=	1.3.2
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://www.unix-heaven.org/FreeBSD/distfiles/

MAINTAINER=	dnaeon@gmail.com
COMMENT=	Interactive tool for package installation

PLIST_FILES=	etc/pkg_add_it.conf \
		man/man1/pkg_add_it.1.gz \
		man/man5/pkg_add_it.conf.5.gz \
		sbin/pkg_add_it

.include <bsd.port.pre.mk>

PKG_RELEASE!=	${UNAME} -r | ${CUT} -d '-' -f 1,2 | ${SED} -e 's|\.[0-9]*.*|-STABLE|'

post-patch:
	${REINPLACE_CMD} -e 's|@PKG_ARCH@|${ARCH}|' \
		-e 's|@PKG_RELEASE@|${PKG_RELEASE:tl}|' ${WRKSRC}/pkg_add_it.conf

do-install:
	${INSTALL_DATA} ${WRKSRC}/pkg_add_it.conf ${STAGEDIR}${PREFIX}/etc
	${INSTALL_PROGRAM} ${WRKSRC}/pkg_add_it ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pkg_add_it.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/pkg_add_it.conf.5 ${STAGEDIR}${MAN5PREFIX}/man/man5

.include <bsd.port.post.mk>
