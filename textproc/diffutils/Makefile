# New ports collection makefile for:	diffutils
# Date created:				5 September 2001
# Whom:				Garrett Rooney <rooneg@electricjellyfish.net>
#
# $FreeBSD$
#

PORTNAME=	diffutils
PORTVERSION=	2.7
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	diffutils

MAINTAINER=	rooneg@electricjellyfish.net

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --program-prefix=g

INSTALL_INFO?=	install-info

post-extract: remove-info-files

remove-info-files:
	@${RM} -f ${WRKSRC}/${PORTNAME:S/utils//}.info*

post-patch: patch-makeinfo

patch-makeinfo:
	@${REINPLACE_CMD} -e 's|makeinfo|makeinfo --no-split|g' \
		${WRKSRC}/Makefile.in

post-install: install-info

install-info:
	@${INSTALL_INFO} ${PREFIX}/info/${PORTNAME:S/utils//}.info ${PREFIX}/info/dir

.include <bsd.port.mk>
