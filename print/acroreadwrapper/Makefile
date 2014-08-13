# Created by: hrs
# $FreeBSD: head/print/acroreadwrapper/Makefile 352986 2014-05-05 09:45:36Z bapt $

PORTNAME=	acroreadwrapper
PORTVERSION=	0.0.20130208
CATEGORIES=	print
MASTER_SITES=	http://people.allbsd.org/~hrs/FreeBSD/
DISTNAME=	linux_adobe_kmod-${PORTVERSION:E}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Wrapper for Adobe Reader

LICENSE=	BSD2CLAUSE

USES=		kmod uidfix

RUN_DEPENDS=	${LOCALBASE}/lib/linux-libgtkembedmoz/libgtkembedmoz.so:${PORTSDIR}/www/linux-libgtkembedmoz

ONLY_FOR_ARCHS=	amd64 i386
PLIST_FILES=	bin/acroread8 bin/acroread9 bin/acroread \
		${RELKMODDIR}/linux_adobe.ko
PLIST_DIRS=	${RELKMODDIR}
SUB_FILES=	acroread
SUB_LIST=	ACROBASE8=${ACROBASE8} \
		ACROBASE9=${ACROBASE9} \
		ADOBE_LANG=${ADOBE_LANG:tu} \
		INSTALLDIR=${INSTALLDIR} \
		LINUXBASE=${LINUXBASE} \
		LINUXSH=${LINUXBASE}/bin/sh \
		PLUGINDIR=${PLUGINDIR} \
		KMODDIR=${RELKMODDIR}
USE_RC_SUBR=	linux_adobe

MAKE_ENV=	DESTDIR=${PREFIX}/

ADOBEBASE=	Adobe
ACROBASE8=	${ADOBEBASE}/Reader8
ACROBASE9=	${ADOBEBASE}/Reader9
PLUGINDIR=	lib/npapi/linux-acroread
KMODDIR=	${PREFIX}/libexec/linux_adobe
RELKMODDIR=	libexec/linux_adobe

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/acroread ${STAGEDIR}${PREFIX}/bin/acroread
	cd ${STAGEDIR}${PREFIX}/bin && ${LN} -s -f acroread acroread8
	cd ${STAGEDIR}${PREFIX}/bin && ${LN} -s -f acroread acroread9

.include <bsd.port.mk>
