# New ports collection makefile for:	texi2html
# Date created:				5 Nov 1997
# Whom:					Ian Vaudrey <i.vaudrey@bigfoot.com>
#
# $FreeBSD$
#

PORTNAME=	texi2html
PORTVERSION=	1.70
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://www.cvshome.org/files/70/10/

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Texinfo to HTML converter

USE_PERL5=	yes
USE_BZIP2=	yes
USE_AUTOMAKE_VER=	15
USE_AUTOCONF_VER=	253
AUTOMAKE_ARGS=	-a
USE_GMAKE=	yes

PROGRAM_PREFIX?=
PLIST_SUB=	PROGRAM_PREFIX=${PROGRAM_PREFIX}

.if !empty(PROGRAM_PREFIX)
CONFIGURE_ARGS=	--program-prefix="${PROGRAM_PREFIX}"
.endif

MAN1=		${PROGRAM_PREFIX}texi2html.1
INFO=		texi2html

pre-everything::
	@${ECHO} ""
	@${ECHO} "You can define the PROGRAM_PREFIX variable to change the name that"
	@${ECHO} "the texi2html program is installed as."
	@${ECHO} ""

.include <bsd.port.mk>
