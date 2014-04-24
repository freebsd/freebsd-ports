# Created by: Tom McLaughlin <tmclaugh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xsi
PORTVERSION=	1.0.b2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/xmlsysinfo/xmlsysinfo/1.0-beta2/
DISTNAME=	${PORTNAME}-1.0-beta2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	System monitor that provides XML encoded stats

USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-user=_xsi

USE_RC_SUBR=	xsi

MAN8=		xsi.8

NO_STAGE=	yes
post-patch:
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e '/^install-data-am/s|install-docDATA||' \
		${WRKSRC}/Makefile.in ${WRKSRC}/doc/Makefile.in
.endif

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 1000000
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
