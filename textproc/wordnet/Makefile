# New ports collection makefile for:	wordnet
# Date created:		26 Feb 2000
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	WordNet
PORTVERSION=	2.0
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.cogsci.princeton.edu/pub/wordnet/${PORTVERSION}/ \
		http://www.cogsci.princeton.edu/${PORTVERSION}/ \
		ftp://ftp.ims.uni-stuttgart.de/pub/WordNet/${PORTVERSION}/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Dictionaries and thesauri with devel. libraries (C, TCL) and browsers

LIB_DEPENDS=	tk${TCL_VER}:${PORTSDIR}/x11-toolkits/tk${TCL_VER}

# The vendor packages up a lot of useless precompiled binaries
# for a few platforms with the source code. Do not extract them:
EXTRACT_AFTER_ARGS= | ${TAR} -xf - --exclude '*/bin/*' \
		--exclude '*/lib/solaris/*' \
		--exclude '*/lib/linux/*' \
		--exclude '*/lib/irix/*' \
		--exclude '*/*.[ao]'

TCL_DVER?=	8.4
TCL_VER=	${TCL_DVER:C/\.//}
SCRIPTS_ENV+=	TCL_DVER=${TCL_DVER} VER=${PORTVERSION}
MAKE_ENV+=	TCL_DVER=${TCL_DVER} VER=${PORTVERSION}
PLIST_SUB+=	TCL_DVER=${TCL_DVER} VER=${PORTVERSION}
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""
INSTALLS_SHLIB=	yes

post-patch:
	${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},g' \
		-e 's,_VER_,${PORTVERSION},g' ${WRKSRC}/include/wnconsts.h \
		${WRKSRC}/src/wnb/wnb

.include <bsd.port.pre.mk>

.for s in 1 3 5 7
MAN$s!=		${MAKE} -f ${FILESDIR}/man.Makefile -V MAN$s
.endfor
MANCOMPRESSED=	maybe

.include <bsd.port.post.mk>
