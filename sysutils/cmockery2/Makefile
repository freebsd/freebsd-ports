#

PORTNAME=	cmockery2
PORTVERSION=	1.3.8
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	harsha@harshavardhana.net
COMMENT=	Cmockery2 revival of Cmockery unit test framework from Google

LICENSE=	APACHE20

USES=		autoreconf libtool pkgconfig
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	lpabon
GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip
# Disable gcov on FreeBSD
# CONFIGURE_ARGS=	--enable-gcov

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/^docdir =/s|-$$(VERSION)||' \
		-e '/^pkgconfigdir =/s|$$(libdir)|$$(prefix)/libdata|' \
		${WRKSRC}/Makefile.am

.include <bsd.port.mk>
