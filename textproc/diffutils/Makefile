# New ports collection makefile for:	diffutils
# Date created:				5 September 2001
# Whom:				Garrett Rooney <rooneg@electricjellyfish.net>
#
# $FreeBSD$
#

PORTNAME=	diffutils
PORTVERSION=	2.8.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	diffutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GNU diff utilities

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g

INFO=		diff

MAN1=		gcmp.1 gdiff.1 gdiff3.1 gsdiff.1

#post-extract: remove-info-files
#
#remove-info-files:
#	@${RM} -f ${WRKSRC}/${PORTNAME:S/utils//}.info*
#
#post-patch: patch-makeinfo
#
#patch-makeinfo:
#	@${REINPLACE_CMD} -e 's|makeinfo|makeinfo --no-split|g' \
#		${WRKSRC}/Makefile.in
#
#post-install: install-info
#
#install-info:
#	@${INSTALL_INFO} ${PREFIX}/info/${PORTNAME:S/utils//}.info ${PREFIX}/info/dir

.include <bsd.port.mk>
