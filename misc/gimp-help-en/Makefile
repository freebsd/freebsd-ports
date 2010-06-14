# New ports collection makefile for:	gimp-help
# Date created:		9th April 2010
# Whom:			SimaMoto,RyoTa <liangtai.s4@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gimp-help
PORTVERSION=	2.6.0
CATEGORIES?=	misc graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/%SUBDIR%/ \
		http://gimp.mirrors.hoobly.com/%SUBDIR%/ \
		http://ftp.gwdg.de/pub/misc/grafik/gimp/%SUBDIR%/ \
		http://www.mirrorservice.org/sites/ftp.gimp.org/pub/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/%SUBDIR%,}
MASTER_SITE_SUBDIR=	gimp/help
PKGNAMEPREFIX?=	${DOCLANG}-
PKGNAMESUFFIX=	-html
DISTNAME=	${PORTNAME}-${PORTVERSION}${PKGNAMESUFFIX}-${DOCLANG}

MAINTAINER=	liangtai.s4@gmail.com
COMMENT?=	The GIMP User Manual in English

USE_BZIP2=	YES
NO_BUILD=	YES
PLIST_SUB=	GIMPDATA=${GIMPDATADIR:S,^${PREFIX}/,,} \
		AMPLE=${AMPLE} DOCLANG=${DOCLANG}

# Though this is document, to be used by the context help system
# of GIMP.  That's why this is not set PORTDOC.
GIMPDATADIR?=	${PREFIX}/share/gimp
DOCLANG?=	en
AMPLE?=	""

do-install:
	@ ${MKDIR} ${GIMPDATADIR}/help ; \
	cd ${WRKDIR}/${PORTNAME}-2/html && \
	${COPYTREE_SHARE} ${DOCLANG} ${GIMPDATADIR}/help

.include <bsd.port.mk>
