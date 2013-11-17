# $FreeBSD$

PORTNAME=	libhtp
PORTVERSION=	0.2.14
CATEGORIES=	www security
PKGNAMESUFFIX=	-suricata

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Security-aware parser for the HTTP protocol

USE_GITHUB=	yes
GH_ACCOUNT=	inliniac
GH_COMMIT=	0294c27

USES=		pkgconfig pathfix
USE_AUTOTOOLS=	aclocal autoconf autoheader automake libtoolize
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	libhtp-[0-9]*

PATHFIX_MAKEFILEIN=	Makefile.am
AUTOMAKE_ARGS+=		--force-missing --add-missing
LIBTOOLIZE_ARGS+=	--force

pre-configure:
	@${REINPLACE_CMD} -Ee 's,^(pkgconfigdir = ).*,\1$$(exec_prefix)/libdata/pkgconfig,' ${WRKSRC}/Makefile.am
	@cd ${WRKSRC} && ${SH} ./autogen.sh

.include <bsd.port.mk>
