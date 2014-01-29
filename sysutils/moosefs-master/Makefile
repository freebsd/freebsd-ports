# Created by: Chifeng Qu <chifeng@gmail.com>
# $FreeBSD$

PORTNAME=	moosefs
PORTVERSION=	#set via include
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-master
NO_STAGE=	yes
.include "bsd.port.moosefs.mk"

MAINTAINER=	chifeng@gmail.com
COMMENT=	Managing the whole filesystem and storing metadata

USE_PYTHON=	yes

USE_RC_SUBR=	mfsmaster mfsmetalogger mfscgiserv
MFS_CGIDIR=	${PREFIX}/share/mfscgi
SUB_FILES+=	pkg-install pkg-message pkg-deinstall
SUB_LIST+=	MFS_WORKDIR="${MFS_WORKDIR}"

CONFIGURE_ARGS+=	--localstatedir=${MFS_WORKDIR} \
			--enable-mfsmaster \
			--with-mfscgiserv-dir=${PREFIX}/sbin \
			--enable-mfscgiserv \
			--enable-mfscgi \
			--with-mfscgi-dir=${MFS_CGIDIR} \
			--disable-mfschunkserver \
			--disable-mfsmount

MAN5=		mfsmaster.cfg.5 mfsexports.cfg.5 mfsmetalogger.cfg.5 mfstopology.cfg.5
MAN7=		moosefs.7 mfs.7
MAN8=		mfscgiserv.8 mfsmaster.8 mfsmetarestore.8 mfsmetalogger.8

.include <bsd.port.pre.mk>

pre-install:
	${MKDIR} ${MFS_CGIDIR}

post-install:
.for FILE in mfsmaster mfsexports mfsmetalogger mfstopology
	@if [ ! -f ${PREFIX}/etc/${FILE}.cfg ]; then \
		${CP} ${PREFIX}/etc/mfs/${FILE}.cfg.dist ${PREFIX}/etc/${FILE}.cfg ; \
	fi
.endfor

	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
