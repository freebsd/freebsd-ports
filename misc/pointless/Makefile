# New ports collection makefile for:   pointless
# Date created:        23 june 2003
# Whom:                Christian Laursen <xi@borderworlds.dk>
#
# $FreeBSD$
#

PORTNAME=	pointless
PORTVERSION=	0.4
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	xi@borderworlds.dk
COMMENT=	Pointless is a presentation tool primarily targeted at the un*x world

.if defined(WITH_GHOSTSCRIPT_AFPL) && ${WITH_GHOSTSCRIPT_AFPL} == yes
GSPORT?=	print/ghostscript-afpl
.else
GSPORT?=	print/ghostscript-gnu
.endif

BUILD_DEPENDS=	${LOCALBASE}/bin/gnuplot:${PORTSDIR}/math/gnuplot \
		${LOCALBASE}/bin/gs:${PORTSDIR}/${GSPORT} \
		${LOCALBASE}/bin/latex:${PORTSDIR}/print/latex \
		${LOCALBASE}/bin/dvips:${PORTSDIR}/print/dvips \
		${LOCALBASE}/bin/a2ps:${PORTSDIR}/print/a2ps-letter \
		${LOCALBASE}/bin/mpost:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_MESA=	yes
USE_PYTHON=	yes
PYTHON_VERSION=	python2.2

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include

MAN1=		pointless.1

CXXFLAGS=	-DHAVE_PYTHON2_2

pre-fetch:
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO} ""
	@${ECHO} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO} ""
.endif

.include <bsd.port.mk>
