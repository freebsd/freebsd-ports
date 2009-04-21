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
CONFIGURE_ARGS+=	--enable-user=_xsi

USE_RC_SUBR=	xsi

MAN8=		xsi.8

post-patch:
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e '/^install-data-am/s|install-docDATA||' \
		${WRKSRC}/Makefile.in ${WRKSRC}/doc/Makefile.in
.endif

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.mk>
