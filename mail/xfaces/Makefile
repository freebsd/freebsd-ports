# New ports collection makefile for:	xfaces-3.3
# Date created:		15 Dec 2001
# Whom:			Ted Faber <faber@isi.edu>
# $FreeBSD$
#

PORTNAME=	xfaces
PORTVERSION=	3.3
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cs.indiana.edu/pub/faces/xfaces/ \
		http://www.mavetju.org/download/adopted/xfaces/
EXTRACT_SUFX=	.tar.Z
DIST_SUBDIR=	${PORTNAME}

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	patch-charnier patch-faber patch-graaff patch-kinzler3
# patch-graff above has a partial pathname in there that none of the others
# do.  The default value for PATCH_DIST_STRIP [-p0] fails on that, this empty
# value keeps any -p option from the patch command and works.
PATCH_DIST_STRIP=

MAINTAINER=	faber@isi.edu
COMMENT=	Display shaped icons for mail spool contents

LIB_DEPENDS=compface:${PORTSDIR}/mail/faces:install

# GNU make properly processes some overridden rules in the makefile that
# imake generates.  Specifically, installing the html docs.
USE_GMAKE=yes
USE_IMAKE=yes

MAN1=		xfaces.1

post-install:
	${MKDIR} ${DATADIR}/images
	${INSTALL_DATA} ${WRKSRC}/images/* ${DATADIR}/images

.include <bsd.port.mk>
