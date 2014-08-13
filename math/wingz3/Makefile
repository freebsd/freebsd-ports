# Created by: erich@rrnet.com
# $FreeBSD: head/math/wingz3/Makefile 361705 2014-07-13 19:35:06Z mi $

PORTNAME=	wingzpro
PORTVERSION=	311
PORTREVISION=	3
CATEGORIES=	math linux
MASTER_SITES=	${MASTER_SITE_SUNSITE}:wingz	\
		${MASTER_SITE_FEDORA_LINUX:M*rpmfind.net/*:S|/fedora/core||}:l
MASTER_SITE_SUBDIR=apps/financial/spreadsheet:wingz	\
		redhat-archive/6.2/en/os/i386/RedHat/RPMS/:l
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:wingz \
		ld.so-1.9.5-13.i386.rpm:l	\
		libc-5.3.12-31.i386.rpm:l
EXTRACT_ONLY=

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Commercial Spreadsheet

NO_PACKAGE=	Commercial software with nothing to build - install from port

IA32_BINARY_PORT=yes
USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
SUB_FILES=	Wingz3
PLIST_SUB+=	LINUXBASE=${LINUXBASE}
OLDLIBS=	libm.so.5 libg++.so.27 libstdc++.so.27 libc.so.5 \
		libXpm.so.4 libXmu.so.6 libXext.so.6 libXt.so.6 \
		libX11.so.6 libICE.so.6 libSM.so.6

NO_BUILD=	yes

do-install:
	${TAR} -xzp -C ${STAGEDIR}${PREFIX}	\
		-f ${DISTDIR}/${_DISTFILES:Mwing*}
	${MKDIR} ${STAGEDIR}${LINUXBASE} ${STAGEDIR}${PREFIX}/Wingz3/lib/libc5
	${TAR} -xp -C ${STAGEDIR}${LINUXBASE}	\
		-f ${DISTDIR}/${_DISTFILES:Mld.so-*} lib/
	${TAR} -xp -C ${STAGEDIR}${PREFIX}/Wingz3/lib/libc5	\
		--strip-components 3 \
		--exclude libXext.so.6.1	\
		-f ${DISTDIR}/${_DISTFILES:Mlibc-*}	\
		${OLDLIBS:S|^|usr/i486-linux-libc5/lib/|:S|$|*|}
.for l in ${OLDLIBS}
	cd ${STAGEDIR}${PREFIX}/Wingz3/lib/libc5 && ${LN} -s $l.* $l
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/Wingz3 ${STAGEDIR}${PREFIX}/bin/Wingz3

.include <bsd.port.mk>
