# New ports collection makefile for:	Quanta+
# Date created:				19 May 2000
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quanta
PORTVERSION= 	3.0pr2a
PORTEPOCH=	1
CATEGORIES=	www kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}

.if !defined(NOPORTDOCS)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		css.tar.bz2 \
		html.tar.bz2 \
		javascript.tar.bz2 \
		php.tar.bz2
.endif

MAINTAINER=	jeremy@external.org

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

USE_KDELIBS_VER=3
USE_XPM=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+= --with-extra-includes=${LOCALBASE}/include \
		--disable-closure \
                --enable-threads \
                --disable-debug
USE_GMAKE=	yes

DOCS=		css html javascript php

post-install:
.if !defined(NOPORTDOCS)
.for doc in ${DOCS}
	cd ${WRKDIR}/${doc} && \
		${CP} -R ${doc} ${doc}.docrc ${PREFIX}/share/apps/quanta/doc
.endfor
	${CHOWN} -R root:wheel ${PREFIX}/share/apps/quanta/doc
	find ${PREFIX}/share/apps/quanta/doc -type f | xargs ${CHMOD} 444
.endif

.include <bsd.port.mk>
