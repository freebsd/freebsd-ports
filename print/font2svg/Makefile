# ex:ts=8
# Ports collection makefile for:	font2svg
# Date created:			Jan 10, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	font2svg
PORTVERSION=	0.1.4
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www.gdv.uni-hannover.de/~peinecke/font2svg/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	All font to svg-font converter

.if defined(WITH_GHOSTSCRIPT_AFPL) && ${WITH_GHOSTSCRIPT_AFPL} == yes
GSPORT?=	print/ghostscript-afpl
.else
GSPORT?=	print/ghostscript-gnu
.endif

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash2 \
		gs:${PORTSDIR}/${GSPORT}

USE_REINPLACE=	yes
NO_BUILD=	yes

pre-fetch:
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO} ""
	@${ECHO} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO} ""
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|/bin/bash|${LOCALBASE}/bin/bash|" \
		-e "s|/home/peinecke/cprog/font2svg|${DATADIR}|" \
		${WRKSRC}/font2svg

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/font2svg ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/encodings ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/font2svg.ps ${DATADIR}

.include <bsd.port.mk>
