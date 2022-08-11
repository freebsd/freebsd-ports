PORTNAME=	vde
PORTVERSION=	2.3.3
DISTVERSIONPREFIX=	v
CATEGORIES=	net
#MASTER_SITES=	https://github.com/virtualsquare/vde-2/archive/refs/tags/
PKGNAMESUFFIX=	2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	User-mode virtual ethernet infrastructure

LICENSE=	BSD3CLAUSE GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libpcap.so.1:net/libpcap

USES=		autoreconf gmake libtool pathfix shebangfix ssl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	virtualsquare
GH_PROJECT=	${PORTNAME}-${PKGNAMESUFFIX}

CONFLICTS=	vde
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
MAKE_ENV=	V=1
MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	CRYPTCAB
OPTIONS_SUB=	yes

CRYPTCAB_DESC=			Enable vde_cryptcab (require security/wolfssl)
CRYPTCAB_LIB_DEPENDS=		libwolfssl.so:security/wolfssl
CRYPTCAB_USES=			localbase:ldflags
CRYPTCAB_CONFIGURE_ENABLE=	cryptcab

post-patch:
	@${REINPLACE_CMD} -e '/-Wall/s|-O2||g' \
		${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's|$$(MAKE).*install-data-hook||g' \
		${WRKSRC}/man/Makefile.am

post-install:
	${LN} -sf unixcmd.1 ${STAGEDIR}${PREFIX}/man/man1/vdecmd.1
	${LN} -sf vdeq.1 ${STAGEDIR}${PREFIX}/man/man1/vdeqemu.1
	${LN} -sf vdeq.1 ${STAGEDIR}${PREFIX}/man/man1/vdekvm.1

.include <bsd.port.mk>
