# New ports collection makefile for:	diffsplit
# Date created:				2002-10-10
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	diffsplit
PORTVERSION=	1.0
CATEGORIES=	textproc devel
MASTER_SITES=	http://www.pathname.com/~quinlan/software/diffsplit/
DISTNAME=	diffsplit
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Splits a unified diff into pieces which patch one file each

NO_BUILD=	YES
NO_WRKSUBDIR=	YES
PLIST_FILES=	bin/diffsplit
USE_PERL5=	YES

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/diffsplit ${WRKDIR}

do-patch:
	@${PERL} -pi -e "s:/usr/bin/perl:${PERL5}:g" ${WRKDIR}/diffsplit

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/diffsplit ${PREFIX}/bin

.include <bsd.port.mk>
