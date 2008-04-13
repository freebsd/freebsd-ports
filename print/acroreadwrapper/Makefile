# New ports collection makefile for:	acroreadwrapper
# Date created:		20 February 2006
# Whom:			hrs
#
# $FreeBSD$
#

PORTNAME=	acroreadwrapper
PORTVERSION=	0.0.20080110
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Wrapper script for Adobe Reader

ONLY_FOR_ARCHS=	amd64 i386
NO_BUILD=	yes
PLIST_FILES=	bin/acroread7 bin/acroread8 bin/acroread
SUB_FILES=	acroread
SUB_LIST=	ACROBASE7=${ACROBASE7} \
		ACROBASE8=${ACROBASE8} \
		ADOBE_LANG=${ADOBE_LANG:U} \
		INSTALLDIR=${INSTALLDIR} \
		LINUXBASE=${LINUXBASE} \
		LINUXSH=${LINUXBASE}/bin/sh \
		PLUGINDIR=${PLUGINDIR} \

ADOBEBASE=	Adobe
ACROBASE7=	${ADOBEBASE}/Acrobat7.0
ACROBASE8=	${ADOBEBASE}/Reader8
PLUGINDIR=	lib/npapi/linux-acroread

do-fetch:
	@${DO_NADA}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/acroread ${PREFIX}/bin/acroread
	cd ${PREFIX}/bin && ${LN} -s -f acroread acroread8
	cd ${PREFIX}/bin && ${LN} -s -f acroread acroread7

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
