# New ports collection makefile for:	pkg_add_it
# Date created:				05 October 2008
# Whom:					Marin Atanasov <dnaeon@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pkg_add_it
PORTVERSION=	1.3.2
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://www.unix-heaven.org/ports-mgmt/

MAINTAINER=	dnaeon@gmail.com
COMMENT=	Interactive tool for package installation

MAN1=		pkg_add_it.1
MAN5=		pkg_add_it.conf.5
PLIST_FILES=	etc/pkg_add_it.conf sbin/pkg_add_it

.include <bsd.port.pre.mk>

PKG_RELEASE!=	${UNAME} -r | ${CUT} -d '-' -f 1,2 | ${SED} -e 's|\.[0-9]*.*|-STABLE|'

post-patch:
	${REINPLACE_CMD} -e 's|@PKG_ARCH@|${ARCH}|' \
		-e 's|@PKG_RELEASE@|${PKG_RELEASE:L}|' ${WRKSRC}/pkg_add_it.conf

do-install:
	${INSTALL_DATA} ${WRKSRC}/pkg_add_it.conf ${PREFIX}/etc/
	${INSTALL_PROGRAM} ${WRKSRC}/pkg_add_it ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/pkg_add_it.1 ${MAN1PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/pkg_add_it.conf.5 ${MAN5PREFIX}/man/man5/

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
