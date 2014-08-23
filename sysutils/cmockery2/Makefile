# Created by: Harshavardhana
# $FreeBSD$
#

PORTNAME=	cmockery2
PORTVERSION=	1.3.8
CATEGORIES=	sysutils
MASTER_SITES=	https://codeload.github.com/lpabon/cmockery2/tar.gz/
DISTNAME=	v1.3.8
EXTRACT_SUFX=

MAINTAINER=	harsha@harshavardhana.net
COMMENT=	Cmockery2 revival of Cmockery unit test framework from Google

LICENSE=	APACHE20

WRKSRC=		${WRKDIR}/cmockery2-${PORTVERSION}

USES=		libtool:build pkgconfig
USE_AUTOTOOLS=	automake autoconf aclocal libtoolize autoheader
AUTOMAKE_ARGS=	--add-missing
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip
# Disable gcov on FreeBSD
# CONFIGURE_ARGS=	--enable-gcov

post-patch:
	@${REINPLACE_CMD} -e '/^docdir =/s|-$$(VERSION)||' \
		-e '/^pkgconfigdir =/s|$$(libdir)|$$(prefix)/libdata|' \
		${WRKSRC}/Makefile.am

.include <bsd.port.mk>
