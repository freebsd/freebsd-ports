# Created by: Chifeng Qu <chifeng@gmail.com>
# $FreeBSD$

PORTNAME=	moosefs
DISTVERSION=	1.6.27-5
CATEGORIES=	sysutils
MASTER_SITES=	http://www.moosefs.org/tl_files/mfscode/ \
		http://ports.quxingwen.com/dist/mfs/
PKGNAMESUFFIX=	-chunkserver
DISTNAME=	mfs-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Storing file data and synchronizing it among themselves

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/mfs-1.6.27
USERS=		mfs
GROUPS=		mfs
GNU_CONFIGURE=	yes

USE_RC_SUBR=	mfschunkserver
SUB_FILES=	pkg-message

CONFIGURE_ARGS=	--localstatedir=/var \
		--enable-mfschunkserver \
		--disable-mfsmaster \
		--disable-mfsmount \
		--disable-mfscgi \
		--disable-mfscgiserv \
		--bindir=${PREFIX}/sbin \
		--with-default-user=mfs \
		--with-default-group=mfs

post-patch:
	${REINPLACE_CMD} -e 's;^general_mans;#general_mans;g' \
		${WRKSRC}/doc/Makefile.am ${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
