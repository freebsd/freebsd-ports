# Created by: Chifeng Qu <chifeng@gmail.com>
# $FreeBSD$

PORTNAME=		moosefs
DISTVERSION=		1.6.27-5
CATEGORIES=		sysutils
MASTER_SITES=		http://www.moosefs.org/tl_files/mfscode/ \
			http://ports.quxingwen.com/dist/mfs/
PKGNAMESUFFIX=		-master
DISTNAME=		mfs-${DISTVERSION}

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Managing the whole filesystem and storing metadata

LICENSE=		GPLv3

WRKSRC=			${WRKDIR}/mfs-1.6.27
USERS=			mfs
GROUPS=			mfs
GNU_CONFIGURE=		yes
USES=			python

USE_RC_SUBR=		mfsmaster mfsmetalogger mfscgiserv
SUB_FILES=		pkg-message
SUB_LIST=		PYTHON_CMD=${PYTHON_CMD}

CONFIGURE_ARGS+=	--localstatedir=/var \
			--enable-mfsmaster \
			--enable-mfscgiserv \
			--enable-mfscgi \
			--disable-mfschunkserver \
			--disable-mfsmount \
			--with-default-user=mfs \
			--with-default-group=mfs \
			--with-mfscgiserv-dir=${PREFIX}/sbin \
			--with-mfscgi-dir=${PREFIX}/share/mfscgi

post-patch:
	${REINPLACE_CMD} -e 's|#\!/usr/bin/env python|#\!${PYTHON_CMD}|' \
		${WRKSRC}/mfscgi/cgiserv.py.in

.include <bsd.port.mk>
