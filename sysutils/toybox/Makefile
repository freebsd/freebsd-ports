PORTNAME=	toybox
PORTVERSION=	0.8.6
CATEGORIES=	sysutils
MASTER_SITES=	http://landley.net/toybox/downloads/

MAINTAINER=	vidar@karlsen.tech
COMMENT=	All-in-one command line

LICENSE=	0BSD
LICENSE_NAME=	BSD Zero Clause License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	bash:shells/bash gsed:textproc/gsed
LIB_DEPENDS=	libinotify.so:devel/libinotify

USES=		gmake shebangfix

SHEBANG_FILES=	scripts/bloatcheck scripts/mcm-buildall.sh \
		scripts/change.sh scripts/findglobals.sh \
		scripts/genconfig.sh scripts/install.sh \
		scripts/make.sh scripts/mkroot.sh \
		scripts/portability.sh scripts/record-commands \
		scripts/runtest.sh scripts/single.sh \
		scripts/test.sh configure \
		tests/*

BIN_LINKS=	[ cat chgrp chmod chown cksum cpio crc32 date dos2unix echo \
		egrep false fgrep fsync grep help hostname kill ln ls mkdir \
		mknod mktemp mountpoint nice pidof printenv pwd rm rmdir sed \
		sleep sync touch true uname unix2dos usleep vmstat
SBIN_LINKS=	killall5 lsmod mkswap modinfo sysctl
USRBIN_LINKS=	acpi ascii base64 basename bunzip2 bzcat cal catv chrt chvt \
		clear cmp comm count cut dirname du expand factor fallocate \
		file find flock fmt groups head hexedit iconv id killall link \
		logger logname lspci lsusb makedevs mkfifo mkpasswd nl nohup \
		od paste patch pmap printf pwdx readlink realpath renice \
		reset rev seq setsid shred sort split strings tac tee test \
		time timeout truncate tty uniq unlink uudecode uuencode \
		uuidgen w watch wc which who whoami xargs xxd yes
USRSBIN_LINKS=	chroot


post-patch:
	${REINPLACE_CMD} -e 's|<sys/inotify.h>|"${LOCALBASE}/include/sys/inotify.h"|' \
		${WRKSRC}/lib/portability.c
	${REINPLACE_CMD} -e 's|sed|gsed|' ${WRKSRC}/scripts/single.sh

do-configure:
	cd ${WRKSRC} && HOSTCC=${CC} ${GMAKE} bsd_defconfig

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/toybox ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}/sbin
	${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}/usr/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}/usr/sbin
.for f in ${BIN_LINKS}
	${LN} -s ../../bin/toybox ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/${f}
.endfor
.for f in ${SBIN_LINKS}
	${LN} -s ../../bin/toybox ${STAGEDIR}${PREFIX}/${PORTNAME}/sbin/${f}
.endfor
.for f in ${USRBIN_LINKS}
	${LN} -s ../../../bin/toybox ${STAGEDIR}${PREFIX}/${PORTNAME}/usr/bin/${f}
.endfor
.for f in ${USRSBIN_LINKS}
	${LN} -s ../../../bin/toybox ${STAGEDIR}${PREFIX}/${PORTNAME}/usr/sbin/${f}
.endfor

.include <bsd.port.mk>
