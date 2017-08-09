# Created by: Ben Woods <woodsb02@FreeBSD.org>
# $FreeBSD$

PORTNAME=	chvt
PORTVERSION=	0.20091101
CATEGORIES=	sysutils
MASTER_SITES=	#
DISTFILES=	#

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Change foreground virtual terminal

LICENSE=	GNUALLPERMISSIVE
LICENSE_NAME=	GNU All-Permissive License
LICENSE_TEXT=	See https://www.gnu.org/prep/maintain/html_node/License-Notices-for-Other-Files.html
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

PLIST_FILES=	bin/chvt

OPTIONS_DEFINE=	SETUID
SETUID_DESC=	Install setuid binary (does not require root priviledges)

do-extract:
	${MKDIR} ${WRKSRC}
#	${CP} ${FILESDIR}/chvt.c ${WRKSRC}/

do-build:
	cd ${WRKSRC} && ${CC} -o ${WRKSRC}/chvt ${FILESDIR}/chvt.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/chvt ${STAGEDIR}${PREFIX}/bin/chvt

post-install-SETUID-on:
	${CHMOD} u+s ${STAGEDIR}${PREFIX}/bin/chvt

.include <bsd.port.mk>
