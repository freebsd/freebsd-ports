# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	numdiff
PORTVERSION=	5.9.0
PORTREVISION=	1
CATEGORIES=	math textproc
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compare putatively similar files, ignoring small numeric differences

LICENSE=	GPLv3

USES=		gmake
GNU_CONFIGURE=	yes
MAKE_ARGS=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}"

INFO=		numdiff

OPTIONS_DEFINE=		DOCS GMP NLS
OPTIONS_DEFAULT=	GMP
OPTIONS_SUB=		yes

GMP_LIB_DEPENDS=	libgmp.so:math/gmp
GMP_CONFIGURE_ENABLE=	gmp
NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
NLS_INSTALL_TARGET=	install install-nls

post-patch:
	@${REINPLACE_CMD} -e \
		'/$$(INFOFILE).gz/s|$$(INSTALL_DATA)|:|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
