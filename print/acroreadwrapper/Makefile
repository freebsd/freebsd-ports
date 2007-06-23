# New ports collection makefile for:	acroreadwrapper
# Date created:		20 February 2006
# Whom:			hrs
#
# $FreeBSD$
#

PORTNAME=	acroreadwrapper
PORTVERSION=	0.0.20060221
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Wrapper script for Adobe Reader

ONLY_FOR_ARCHS=	amd64 i386
USE_X_PREFIX=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/acroread
SUB_FILES=	acroread
SUB_LIST=	ACROBASE=${ACROBASE} \
		ADOBE_LANG=${ADOBE_LANG:U} \
		INSTALLDIR=${INSTALLDIR} \
		LINUXBASE=${LINUXBASE} \
		PLUGINDIR=${PLUGINDIR}

ADOBEBASE=	Adobe
ACROBASE=	${ADOBEBASE}/Acrobat7.0
PLUGINDIR=	lib/browser_linux_plugins

do-fetch:
	@${DO_NADA}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/acroread ${PREFIX}/bin/acroread

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
