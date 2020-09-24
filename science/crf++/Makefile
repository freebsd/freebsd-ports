# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	crf++
# 0.59 as defined in
# https://github.com/taku910/crfpp/commit/d78526835e4cfcc4822156724edda8a3839327c2
DISTVERSION=	0.59
PORTREVISION=	1
CATEGORIES=	science math
PATCH_SITES=	https://patch-diff.githubusercontent.com/raw/taku910/crfpp/pull/:pr
PATCHFILES=	15.patch:-p1:pr \
		16.patch:-p1:pr

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet Another CRF toolkit

LICENSE=	BSD3CLAUSE LGPL21+
LICENSE_COMB=	dual
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/BSD
LICENSE_FILE_LGPL21+ =	${WRKSRC}/LGPL

USES=		libtool
USE_GITHUB=	yes
GH_ACCOUNT=	taku910
GH_PROJECT=	crfpp
GH_TAGNAME=	1dc92a606f874a4fe52603803364cc1d90f952fb
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PORTEXAMPLES=	JapaneseNE basenp chunking seg

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAPLESDIR}
	(cd ${WRKSRC}/example && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
