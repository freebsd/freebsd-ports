PORTNAME=	isal
DISTVERSION=	g20211021
CATEGORIES=	security
PKGNAMESUFFIX=	-kmod

MAINTAINER=	jhb@FreeBSD.org
COMMENT=	Kernel crypto driver using Intel(R) ISA-L crypto

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/isa-l_crypto/LICENSE

IGNORE_FreeBSD_12=	requires FreeBSD 13.0 or later
ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	yasm:devel/yasm

USES=		kmod uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	bsdjhb
GH_PROJECT=	ocf_isa_l
GH_TAGNAME=	7cf3a29
GH_TUPLE=	intel:isa-l_crypto:v2.22.0:isal_crypto/isa-l_crypto

PLIST_FILES=	${KMODDIR}/isal.ko \
		man/man4/isal.4.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/isal.4 ${STAGEDIR}${MANPREFIX}/man/man4/isal.4

.include <bsd.port.mk>
