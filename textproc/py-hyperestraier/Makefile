# New ports collection makefile for:    py-hyperestraier
# Date created:                         21 November 2006
# Whom:                                 Junji NAKANISHI <jun-g@daemonfreaks.com>
#
# $FreeBSD$

PORTNAME=	hyperestraier
PORTVERSION=	0.0.15
CATEGORIES=	textproc python
MASTER_SITES=	http://hyperestraier.sourceforge.net/binding/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	hyper_estraier_wrappers-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python bindings for HyperEstraier

BUILD_DEPENDS=	swig>=1.3:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	estraier.8:${PORTSDIR}/textproc/hyperestraier

USE_PYTHON=	yes
INSTALLS_EGGINFO=	yes
PYDISTUTILS_PKGNAME=	HyperEstraier
PYDISTUTILS_PKGVERSION=	0.01

MAKE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

pre-patch:
	@${REINPLACE_CMD} -e 's|PYTHON = python|PYTHON = ${PYTHON_VERSION}|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
