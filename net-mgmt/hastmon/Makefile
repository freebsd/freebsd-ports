# Created by: Mikolaj Golub <to.my.trociny@gmail.com>
# $FreeBSD$

PORTNAME=	hastmon
PORTVERSION=	0.3.1
CATEGORIES=	net-mgmt
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	Cluster monitoring daemon

LICENSE=	BSD

BUILD_DEPENDS=	mk-configure>=0.20:${PORTSDIR}/devel/mk-configure

MKCMAKE?=	${LOCALBASE}/bin/mkcmake
INSTALL_TARGET=	installdirs install

PORTDOCS=	ChangeLog COPYRIGHT README

MAN5=		hastmon.conf.5
MAN8=		hastmon.8 hastmonctl.8

PLIST_FILES=	sbin/hastmon \
		sbin/hastmonctl \
		etc/rc.d/hastmon

do-build:
	${SETENV} ${MKCMAKE_ENV} ${MKCMAKE} -C ${WRKSRC}

do-install:
	${SETENV} ${MKCMAKE_ENV} ${MKCMAKE} -C ${WRKSRC} ${INSTALL_TARGET}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
