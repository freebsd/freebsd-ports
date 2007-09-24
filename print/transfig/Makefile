# New ports collection makefile for:	transfig
# Date created:		9 August 1996
# Whom:			chuckr@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	transfig
PORTVERSION=	3.2.5
CATEGORIES=	print
MASTER_SITES=	http://xfig.org/software/xfig/${PORTVERSION}/ \
		ftp://www-epb.lbl.gov/xfig/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools to convert Xfig's .fig files

RUN_DEPENDS=	ppmtogif:${PORTSDIR}/graphics/netpbm
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_GHOSTSCRIPT_RUN=	yes
USE_IMAKE=	yes
USE_XPM=	yes
MAN1=		fig2dev.1 fig2ps2tex.1 pic2tpic.1 transfig.1

MAKE_ARGS+=	INSTALLFLAGS="${COPY}" \
		INSTPGMFLAGS="${STRIP} ${_BINOWNGRP} -m ${BINMODE}" \
		INSTBINFLAGS="${_BINOWNGRP} -m ${BINMODE}" \
		INSTDATFLAGS="${_SHROWNGRP} -m ${SHAREMODE}" \
		INSTMANFLAGS="${_MANOWNGRP} -m ${MANMODE}"

pre-everything::
.if !defined(WITH_GHOSTSCRIPT_GNU)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "      Define WITH_GHOSTSCRIPT_GNU=yes to use"
	@${ECHO_MSG} "      GNU Postscript interpreter instead of GPL one"
	@${ECHO_MSG} ""
.endif

.include <bsd.port.mk>
