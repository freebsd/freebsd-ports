# Created by: Sergei Kolobov <sergei@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cvm
PORTVERSION=	0.96
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://untroubled.org/${PORTNAME}/ \
		http://untroubled.org/${PORTNAME}/archive/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Credential Validation Modules

LICENSE=	GPLv2

LIB_DEPENDS=	libbg.so:devel/bglibs

CONFLICTS=	bglibs-1.00*

USES=		libtool:build
USE_LDCONFIG=	yes
BGLIBS_INC=	${LOCALBASE}/include/bglibs
BGLIBS_LIB=	${LOCALBASE}/lib/bglibs

DOCS=		NEWS README TODO *.html

ALL_TARGET=	all

OPTIONS_DEFINE=	DOCS VCHKPW

OPTIONS_SUB=	yes

VCHKPW_DESC=	Compile cvm-vchkpw

VCHKPW_ALL_TARGET=	cvm-vchkpw

VCHKPW_BUILD_DEPENDS=	${LOCALBASE}/vpopmail/lib/libvpopmail.a:mail/vpopmail

do-configure:
	${ECHO_CMD} "${PREFIX}"		> ${WRKSRC}/conf-home
	${ECHO_CMD} "${STAGEDIR}${PREFIX}/bin"	> ${WRKSRC}/conf-bin
	${ECHO_CMD} "${STAGEDIR}${PREFIX}/include"	> ${WRKSRC}/conf-include
	${ECHO_CMD} "${STAGEDIR}${PREFIX}/lib"	> ${WRKSRC}/conf-lib
	${ECHO_CMD} "${CC} ${CFLAGS}"	> ${WRKSRC}/conf-cc
	${ECHO_CMD} "${CC} ${STRIP} ${LDFLAGS}"       > ${WRKSRC}/conf-ld
	${ECHO_CMD} "${BGLIBS_INC}"	> ${WRKSRC}/conf-bgincs
	${ECHO_CMD} "${BGLIBS_LIB}"	> ${WRKSRC}/conf-bglibs

post-install:
.for l in command local module qmail sasl sql udp v1client v2client
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}-${l}.so*
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
