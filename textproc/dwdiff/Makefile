# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	dwdiff
PORTVERSION=	2.0.9
PORTREVISION=	6
CATEGORIES=	textproc
MASTER_SITES=	http://os.ghalkes.nl/dist/ \
		http://fossies.org/unix/privat/
EXTRACT_SUFX=	.tgz

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Delimited word diff program

LICENSE=	GPLv3

OPTIONS_DEFINE=	UNICODE NLS DOCS
OPTIONS_DEFAULT=UNICODE
OPTIONS_SUB=	yes

NLS_CONFIGURE_WITH=	gettext
NLS_USES=	gettext

UNICODE_CONFIGURE_WITH=	unicode
UNICODE_LIB_DEPENDS=	libicudata.so:devel/icu

HAS_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man

post-patch:
	@${REINPLACE_CMD} -e 's|share/doc/${PORTNAME}-${PORTVERSION}|${DOCSDIR_REL}|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
