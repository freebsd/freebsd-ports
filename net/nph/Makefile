# Created by: Jim Pirzyk <pirzyk@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nph
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.feep.net/pub/software/nph/

MAINTAINER=	pirzyk@FreeBSD.org
COMMENT=	New PH Client and API Library

HAS_CONFIGURE=	YES
CONFIGURE_ARGS=	--disable-encap --disable-epkg-install

do-install:
	@(cd ${BUILD_WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install-recurse)

	-@${MKDIR} ${STAGEDIR}${PREFIX}/etc
	@${CP} ${BUILD_WRKSRC}/nphrc ${STAGEDIR}${PREFIX}/etc/nphrc.sample
	PKG_PREFIX=${STAGEDIR}${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

post-clean:
	@${RM} ${STAGEDIR}${PREFIX}/etc/ph_server

.include <bsd.port.mk>
