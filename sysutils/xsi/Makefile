# New ports collection makefile for:	xsi
# Date created:        			18 October 2006
# Whom:					Tom McLaughlin <tmclaugh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xsi
PORTVERSION=	1.0.b2
CATEGORIES=	sysutils
MASTER_SITES=	http://xsi.kolabore.ath.cx/download/
DISTNAME=	${PORTNAME}-1.0-beta2

MAINTAINER=	tmclaugh@FreeBSD.org
COMMENT=	System monitor that provides XML encoded stats

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--mandir=${MANPREFIX}/man \
			--enable-user=_xsi

USE_RC_SUBR=	xsi

MAN8=		xsi.8

post-configure:
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's|-exec-am install-data-am|-exec-am|' \
		${WRKSRC}/Makefile
.endif

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.pre.mk>

.if (${OSVERSION} < 600007)
IGNORE=		is not supported on FreeBSD < 6.0
.endif

.include <bsd.port.post.mk>
