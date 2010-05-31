# New ports collection makefile for:	flex
# Date created:		13 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flex
PORTVERSION=	2.5.35
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Fast lexical analyzer generator

BUILD_DEPENDS=	help2man:${PORTSDIR}/misc/help2man \
		gm4:${PORTSDIR}/devel/m4

USE_BISON=	build
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
# install flex header to its own dir to avoid conflict with system flex.
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/flex
USE_GMAKE=	yes
MAN1=		flex.1
INFO=		flex

.if !defined(WITHOUT_NLS)
USE_ICONV=	yes
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:	.SILENT
	${REINPLACE_CMD} -Ee 's/tests//' \
		-e 's/^([[:space:]]*)\$$\(RANLIB\) ([^ ;]*)/\1chmod u+w \2;&/' \
		${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's/@MAKEINFO@/& --no-split/g' \
		${WRKSRC}/doc/Makefile.in
	${RM} -f ${WRKSRC}/doc/*.info*

.include <bsd.port.mk>
