# New ports collection makefile for:    moosefs-client
# Date created:         1 April 2010
# Whom:                 Chifeng Qu <chifeng@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	moosefs
PORTREVISION=	#
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-client
.include "${.CURDIR}/../moosefs-master/bsd.port.moosefs.mk"

MAINTAINER=	chifeng@gmail.com
COMMENT=	Moosefs client tools

DISTINFO_FILE=	${.CURDIR}/../moosefs-master/distinfo

BUILD_DEPENDS=	${LOCALBASE}/include/fuse.h:${PORTSDIR}/sysutils/fusefs-libs
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod

USE_PKGCONFIG=	yes

MAN1=		mfstools.1 mfscheckfile.1 mfsdirinfo.1 mfsfileinfo.1 \
		mfsfilerepair.1 mfsgetgoal.1 mfsgettrashtime.1 \
		mfsrgetgoal.1 mfsrgettrashtime.1 mfsrsetgoal.1 \
		mfsrsettrashtime.1 mfssetgoal.1 mfssettrashtime.1 \
		mfsgeteattr.1 mfsseteattr.1 mfsdeleattr.1 \
		mfsappendchunks.1 mfsmakesnapshot.1
MAN8=		mfsmount.8

CONFIGURE_ARGS=	--with-default-user=${MFSUSER} \
		--with-default-group=${MFSGROUP} \
		--disable-mfsmaster \
		--disable-mfschunkserver \
		--disable-mfscgi \
		--disable-mfscgiserv \
		--enable-mfsmount

post-patch:
	${REINPLACE_CMD} -e 's;^general_mans;#general_mans;g' ${WRKSRC}/doc/Makefile.am \
		${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
