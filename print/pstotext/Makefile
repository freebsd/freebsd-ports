# New ports collection makefile for:	pstotext
# Date created:		December 6, 1999
# Whom:			Oliver Breuninger <ob@seicom.NET>
#
# $FreeBSD$
#

PORTNAME=	pstotext
PORTVERSION=	1.8g
CATEGORIES=	print
MASTER_SITES=	http://www.breuninger.org/files/distfiles/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ob@breuninger.org
COMMENT=	A PostScript to Text converter

USE_GHOSTSCRIPT_RUN=	yes

MAN1=		pstotext.1
PLIST_FILES=	bin/pstotext

pre-everything::
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO} ""
	@${ECHO} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO} ""
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pstotext ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pstotext.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
