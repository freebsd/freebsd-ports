# ports collection makefile for:	jigdo
# Date created:				23 July 2002
# Whom:					Attila Nagy <bra@fsn.hu>
#
# $FreeBSD$
#

PORTNAME=	jigdo
PORTVERSION=	0.7.1
CATEGORIES=	ftp
MASTER_SITES=	http://atterer.net/jigdo/

MAINTAINER=	bra@fsn.hu
COMMENT=	A utility used to retrieve very large files over the Internet

BUILD_DEPENDS=	libwww-config:${PORTSDIR}/www/libwww \
		${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget

MAN1=		jigdo-file.1 jigdo-lite.1 jigdo-mirror.1

USE_BZIP2=	yes
USE_SUBMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-libdb --disable-nls --without-gui
USE_GMAKE=	yes

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}" \

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
NOT_FOR_ARCHS+=	alpha
.endif

pre-fetch:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.jigdo

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/jigdo-file

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.include <bsd.port.post.mk>
