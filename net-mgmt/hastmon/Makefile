# New ports collection makefile for:	hastmon
# Date created:				23 October 2010
# Whom:					Mikolaj Golub <to.my.trociny@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	hastmon
PORTVERSION=	0.3.0
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	to.my.trociny@gmail.com
COMMENT=	Cluster monitoring daemon

BUILD_DEPENDS=	mk-configure>=0.20:${PORTSDIR}/devel/mk-configure

LICENSE=	BSD

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
