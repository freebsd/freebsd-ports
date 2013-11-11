# Created by: Seth Kingsley <sethk@meowfishies.com>
# $FreeBSD$

PORTNAME=	ymessenger
PORTVERSION=	1.0.6.1
CATEGORIES=	net-im
MASTER_SITES=	http://public.yahoo.com/%7Emmk/
PKGNAMEPREFIX=	linux-
DISTNAME=	rh9.${PORTNAME}-${PORTVERSION:C/\.([^\.]+)$/-\1/}.i386
DISTFILES=	${DISTNAME}.rpm ymessenger.bin
EXTRACT_ONLY=	${DISTNAME}.rpm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RPM of Yahoo! Messenger instant messaging client

DEPRECATED=	Depends on deprecated Linux GTK1
EXPIRATION_DATE=2013-12-01

EXTRACT_DEPENDS=	rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio

USE_LINUX=	yes
USE_LINUX_APPS=	gdkpixbuf gtk

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

ONLY_FOR_ARCHS=	i386 amd64

SHARE_FILES=	yahoo_gnome.png yahoo_kde.xpm ymessenger.desktop\
		ymessenger.kdelnk

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@for rpm in ${EXTRACT_ONLY}; do\
	    (cd ${WRKDIR} &&\
	    rpm2cpio.pl ${DISTDIR}/${DIST_SUBDIR}/${DISTFILE}/$$rpm |\
	    ${CPIO} --quiet -idm);\
	done

pre-patch:
	${CP} -fp ${DISTDIR}/ymessenger.bin ${WRKDIR}/opt/ymessenger/bin

post-patch:
	${SED} -e 's:%%PREFIX%%:${PREFIX}:g' ${FILESDIR}/linux-ymessenger.sh >\
	    ${WRKDIR}/linux-ymessenger.sh

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/linux-ymessenger
.for f in ${SHARE_FILES}
	${INSTALL_DATA} ${WRKDIR}/opt/ymessenger/bin/${f}\
	    ${STAGEDIR}${PREFIX}/libexec/linux-ymessenger
.endfor
	${INSTALL_PROGRAM} ${WRKDIR}/opt/ymessenger/bin/ymessenger.bin\
	    ${STAGEDIR}${PREFIX}/libexec/linux-ymessenger
	${INSTALL_SCRIPT} ${WRKDIR}/linux-ymessenger.sh\
	    ${STAGEDIR}${PREFIX}/bin/linux-ymessenger
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/linux-ymessenger
	${INSTALL_DATA} ${WRKDIR}/opt/ymessenger/lib/libgtkhtml.so.0\
	    ${STAGEDIR}${PREFIX}/lib/linux-ymessenger

.include <bsd.port.mk>
