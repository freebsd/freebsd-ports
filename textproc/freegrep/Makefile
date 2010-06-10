# New ports collection makefile for:	grep
# Date created:		8 June 1999
# Whom:			Sheldon Hearn <sheldonh@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	freegrep
PORTVERSION=	1.1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.jameshoward.us/pub/howardjp/grep/ 		\
		http://github.com/downloads/howardjp/freegrep/
DISTNAME=	grep-${PORTVERSION}

MAINTAINER=	jh@jameshoward.us
COMMENT=	An implementation of grep(1) under a BSD-friendly license

USE_BZIP2=	YES

PLIST_FILES=	bin/grep	\
		bin/egrep	\
		bin/fgrep	\
		bin/zgrep   \
		bin/zegrep  \
		bin/zfgrep

MAN1=		grep.1 egrep.1 fgrep.1 zgrep.1 zegrep.1 zfgrep.1

post-extract:
	@(cd ${WRKSRC}; ${RM} -f .depend)

.include <bsd.port.mk>
