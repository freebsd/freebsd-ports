# New ports collection makefile for:	acroreadwrapper
# Date created:		20 February 2006
# Whom:			hrs
#
# $FreeBSD$
#

PORTNAME=	acroreadwrapper
PORTVERSION=	0.0.20110920
CATEGORIES=	print
MASTER_SITES=	http://people.allbsd.org/~hrs/FreeBSD/
DISTNAME=	linux_adobe_kmod-${PORTVERSION:S,0.0.,,}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Wrapper script for Adobe Reader

RUN_DEPENDS=	${LOCALBASE}/lib/linux-libgtkembedmoz/libgtkembedmoz.so:${PORTSDIR}/www/linux-libgtkembedmoz

ONLY_FOR_ARCHS=	amd64 i386
PLIST_FILES=	bin/acroread8 bin/acroread9 bin/acroread \
		${KMODDIR}/linux_adobe.ko
PLIST_DIRS=	${KMODDIR}
SUB_FILES=	acroread
SUB_LIST=	ACROBASE8=${ACROBASE8} \
		ACROBASE9=${ACROBASE9} \
		ADOBE_LANG=${ADOBE_LANG:U} \
		INSTALLDIR=${INSTALLDIR} \
		LINUXBASE=${LINUXBASE} \
		LINUXSH=${LINUXBASE}/bin/sh \
		PLUGINDIR=${PLUGINDIR} \
		KMODDIR=${KMODDIR}
USE_RC_SUBR=	linux_adobe

.include <bsd.port.pre.mk>

MAKE_ENV=	KMODDIR=${KMODDIR} SYSDIR=${SRC_BASE}/sys DESTDIR=${PREFIX}/

ADOBEBASE=	Adobe
ACROBASE8=	${ADOBEBASE}/Reader8
ACROBASE9=	${ADOBEBASE}/Reader9
PLUGINDIR=	lib/npapi/linux-acroread
KMODDIR=	libexec/linux_adobe

KERNCONF?=	GENERIC

# Use the first component of ${KERNCONF}.
.for K in ${KERNCONF}
_KERNCONF?=$K
.endfor

.if !exists(${SRC_BASE}/sys/${ARCH}/conf/${_KERNCONF})
IGNORE=		requires kernel source to be installed
.endif

post-install:
	${INSTALL_KLD} ${WRKSRC}/linux_adobe.ko \
		${PREFIX}/libexec/linux_adobe/linux_adobe.ko
	${INSTALL_SCRIPT} ${WRKDIR}/acroread ${PREFIX}/bin/acroread
	cd ${PREFIX}/bin && ${LN} -s -f acroread acroread8
	cd ${PREFIX}/bin && ${LN} -s -f acroread acroread9

.include <bsd.port.post.mk>
