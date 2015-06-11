# Created by: Chifeng Qu <chifeng@gmail.com>
# $FreeBSD$

PORTNAME=	moosefs
DISTVERSION=	1.6.27-5
CATEGORIES=	sysutils
MASTER_SITES=	http://www.moosefs.org/tl_files/mfscode/ \
		http://ports.quxingwen.com/dist/mfs/
PKGNAMESUFFIX=	-client
DISTNAME=	mfs-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Moosefs client tools

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/mfs-1.6.27
GNU_CONFIGURE=	yes

USES=		fuse pkgconfig

CONFIGURE_ARGS=	--disable-mfsmaster \
		--disable-mfschunkserver \
		--disable-mfscgi \
		--disable-mfscgiserv \
		--enable-mfsmount

post-patch:
	${REINPLACE_CMD} -e 's;^general_mans;#general_mans;g' \
		${WRKSRC}/doc/Makefile.am ${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
