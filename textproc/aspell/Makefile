# New ports collection makefile for:	aspell
# Date created:				7 December 1998
# Whom:					Josh Gilliam <josh@quick.net>
#
# $FreeBSD$
#

PORTNAME=	aspell
PORTVERSION=	0.50.1
CATEGORIES=	textproc
MASTER_SITES=	http://savannah.gnu.org/download/${PORTNAME}/rel/	\
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	thierry@pompo.net

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash2

USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--enable-dict-dir=${DATADIR} \
		--enable-doc-dir=${DOCSDIR}
USE_GMAKE=	yes
USE_REINPLACE=	yes

MAKE_ARGS=	NOPORTDOCS=${NOPORTDOCS}
INSTALLS_SHLIB=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
