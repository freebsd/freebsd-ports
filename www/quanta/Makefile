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
PORTEPOCH=	2	# dammit! I hate this kludge.
CATEGORIES=	www kde

MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	alane#/quanta
DIST_SUBDIR=		${PORTNAME}

.if !defined(NOPORTDOCS)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		css.tar.bz2 \
		html.tar.bz2 \
		javascript.tar.bz2 \
		php.tar.bz2
.endif

MAINTAINER=	alane@freebsd.org

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

USE_KDELIBS_VER=3
USE_XPM=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+= --with-extra-includes=${LOCALBASE}/include \
		--disable-closure --enable-threads --disable-debug
USE_GMAKE=	yes

DOCS=		css html javascript php

QDOCSDIR=	share/apps/quanta/doc
PLIST_SUB+=	QDOCSDIR=${QDOCSDIR} DOCSDIR=${DOCSDIR}

.include <bsd.port.pre.mk>

pre-configure:
	cd ${WRKSRC}; ${GMAKE} -f Makefile.cvs

post-install:
	${RM} -fr ${PREFIX}/${QDOCSDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${QDOCSDIR}
.for doc in ${DOCS}
	cd ${WRKDIR}/${doc}; ${CP} -R ${doc} ${doc}.docrc ${PREFIX}/${QDOCSDIR}
.endfor # doc in ${DOCS}
	${CHOWN} -R ${DOCOWN}:${DOCGRP} ${PREFIX}/${QDOCSDIR}
	${FIND} ${PREFIX}/${QDOCSDIR}|sort|xargs ${CHMOD} ${DOCMODE}
	${FIND} ${PREFIX}/${QDOCSDIR} -type d|sort|xargs ${CHMOD} ugo+x
.endif # !defined(NOPORTDOCS)
	if ${TEST} -f ${PKGMESSAGE}; then ${CAT} ${PKGMESSAGE}; fi 

.include <bsd.port.post.mk>
