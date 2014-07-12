PORTVERSION=	1.6.27
PORTREVISION?=	1
MASTER_SITES=	http://www.moosefs.org/tl_files/mfscode/ \
		http://ports.quxingwen.com/dist/mfs/

DISTNAME=	mfs-${PORTVERSION}-1
WRKSRC=		${WRKDIR}/mfs-${PORTVERSION}

LICENSE=	GPLv3

USERS=		mfs
GROUPS=		mfs
GNU_CONFIGURE=	yes
MFS_WORKDIR=	/var
