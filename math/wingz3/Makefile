# Created by: erich@rrnet.com
# $FreeBSD$

PORTNAME=	wingzpro
PORTVERSION=	311
PORTREVISION=	3
CATEGORIES=	math linux
MASTER_SITES=	SUNSITE/apps/financial/spreadsheet:wingz
# MASTER_SITE_FEDORA_LINUX does not contain rpmfind.net, so this does not do anything
#		${MASTER_SITE_FEDORA_LINUX:M*rpmfind.net/*:S|/fedora/core||}:l
MASTER_SITE_SUBDIR= redhat-archive/6.2/en/os/i386/RedHat/RPMS/:l
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:wingz \
		ld.so-1.9.5-13.i386.rpm:l	\
		libc-5.3.12-31.i386.rpm:l
EXTRACT_ONLY=

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Commercial Spreadsheet

BROKEN=		unfetchable

NO_PACKAGE=	Commercial software with nothing to build - install from port

IA32_BINARY_PORT=yes
USES=		linux
USE_LINUX=	xorglibs
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
