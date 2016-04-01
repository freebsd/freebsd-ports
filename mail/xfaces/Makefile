# Created by: Ted Faber <faber@isi.edu>
# $FreeBSD$

PORTNAME=	xfaces
PORTVERSION=	3.3
PORTREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cs.indiana.edu/pub/faces/xfaces/ \
		http://www.mavetju.org/download/adopted/xfaces/
DIST_SUBDIR=	${PORTNAME}

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	patch-charnier patch-faber patch-graaff patch-kinzler3
# patch-graff above has a partial pathname in there that none of the others
# do.  The default value for PATCH_DIST_STRIP [-p0] fails on that, this empty
# value keeps any -p option from the patch command and works.
PATCH_DIST_STRIP=

MAINTAINER=	faber@isi.edu
COMMENT=	Display shaped icons for mail spool contents

LIB_DEPENDS=	libcompface.so:mail/faces

# GNU make properly processes some overridden rules in the makefile that
# imake generates.  Specifically, installing the html docs.
USES=		imake gmake tar:Z
USE_XORG=	ice sm x11 xaw xext xmu xt xpm

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/images
	${INSTALL_DATA} ${WRKSRC}/images/* ${STAGEDIR}${DATADIR}/images

.include <bsd.port.mk>
