PORTVERSION=	1.6.25
PORTREVISION?=	0
MASTER_SITES=	http://www.moosefs.org/tl_files/mfscode/ \
		http://ports.quxingwen.com/dist/mfs/

DISTNAME=	mfs-${PORTVERSION}

LICENSE=	GPLv3

USERS=		mfs
GROUPS=		mfs
GNU_CONFIGURE=	yes
MFS_WORKDIR=	/var
