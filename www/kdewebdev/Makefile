# New ports collection makefile for:	Quanta+
# Date created:				26 Sep 2002
# Whom:					AlanE <alane@freebsd.org>
#
# $FreeBSD$
#

# NOTE: This is the official release version of quanta which will be
# included in kde-3.1. Yay!

PORTNAME=	quanta
PORTVERSION= 	3.0
PORTREVISION=	4
PORTEPOCH=	2	# dammit! I hate this kludge.
CATEGORIES=	www kde

MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DIST_SUBDIR=		${PORTNAME}

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		css.tar.bz2 \
		html.tar.bz2 \
		javascript.tar.bz2 \
		php.tar.bz2

MAINTAINER=	kde@freebsd.org

BUILD_DEPENDS=	xgettext:${PORTSDIR}/devel/gettext	\
		autoconf:${PORTSDIR}/devel/autoconf	\
		automake:${PORTSDIR}/devel/automake

ACLOCAL=	aclocal
AUTOCONF=	autoconf
AUTOHEADER=	autoheader
AUTOMAKE=	automake

USE_KDELIBS_VER=3
USE_XPM=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+= --with-extra-includes=${LOCALBASE}/include \
		--disable-closure --enable-threads --disable-debug
USE_GMAKE=	yes

DOCS=		css html javascript php

KDOCSDIR=	share/doc/HTML/en
QDOCSDIR=	share/apps/quanta/doc
PLIST_SUB+=	KDOCSDIR=${KDOCSDIR} QDOCSDIR=${QDOCSDIR}

.include <bsd.port.pre.mk>

pre-configure:
	cd ${WRKSRC}; ${GMAKE} -f Makefile.cvs

post-install:
	${MKDIR} ${PREFIX}/${QDOCSDIR}
.for doc in ${DOCS}
	cd ${WRKDIR}/${doc}; ${CP} -R ${doc} ${doc}.docrc ${PREFIX}/${QDOCSDIR}
.endfor # doc in ${DOCS}
	${CHOWN} -R ${DOCOWN}:${DOCGRP} ${PREFIX}/${QDOCSDIR}
	${FIND} ${PREFIX}/${QDOCSDIR}|sort|xargs ${CHMOD} ${DOCMODE}
	${FIND} ${PREFIX}/${QDOCSDIR} -type d|sort|xargs ${CHMOD} ugo+x
	if ${TEST} -f ${PKGMESSAGE}; then ${CAT} ${PKGMESSAGE}; fi 

.include <bsd.port.post.mk>
