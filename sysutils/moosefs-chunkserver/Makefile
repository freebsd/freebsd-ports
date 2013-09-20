# Created by: Chifeng Qu <chifeng@gmail.com>
# $FreeBSD$

PORTNAME=	moosefs
PORTVERSION=	#
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-chunkserver
NO_STAGE=	yes
.include "${.CURDIR}/../moosefs-master/bsd.port.moosefs.mk"

MAINTAINER=	chifeng@gmail.com
COMMENT=	Storing files data and synchronizing it among themselves

DISTINFO_FILE=	${.CURDIR}/../moosefs-master/distinfo
USE_RC_SUBR=	mfschunkserver

MAN5=		mfschunkserver.cfg.5 mfshdd.cfg.5
MAN8=		mfschunkserver.8

SUB_FILES+=	pkg-message pkg-deinstall
SUB_LIST+=	MFS_WORKDIR="${MFS_WORKDIR}"

CONFIGURE_ARGS=	--localstatedir=${MFS_WORKDIR} \
		--bindir=${PREFIX}/sbin \
		--with-default-user=${MFSUSER} \
		--with-default-group=${MFSGROUP} \
		--disable-mfsmaster \
		--disable-mfsmount \
		--disable-mfscgi \
		--disable-mfscgiserv \
		--enable-mfschunkserver

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's;^general_mans;#general_mans;g' ${WRKSRC}/doc/Makefile.am \
		${WRKSRC}/doc/Makefile.in

post-install:
.for FILE in mfschunkserver mfshdd
	@if [ ! -f ${PREFIX}/etc/${i}.cfg ]; then \
		${CP} ${PREFIX}/etc/mfs/${FILE}.cfg.dist ${PREFIX}/etc/${FILE}.cfg ; \
	fi
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
