# New ports collection makefile for:	textutils
# Version required:	2.0
# Date created:		14 May 1998
# Whom:			Adrian Wontroba <aw1@stade.co.uk>
#
# $FreeBSD$
#

DISTNAME=	textutils-2.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	textutils

MAINTAINER=	aw1@stade.co.uk

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--program-prefix=g

USE_GMAKE=	yes

MAN1=		gcomm.1 gcsplit.1 gcut.1 gexpand.1 gfmt.1 ghead.1 \
		gjoin.1 gmd5sum.1 gnl.1 gpaste.1 gpr.1 gsort.1 \
		gptx.1 gsum.1 gtac.1 gtail.1 gtr.1 guniq.1 \
		gtsort.1 gwc.1 gcat.1 gcksum.1 gfold.1 god.1 \
		gsplit.1 gunexpand.1

post-install:
	install-info ${PREFIX}/info/textutils.info ${PREFIX}/info/dir

.include <bsd.port.mk>
