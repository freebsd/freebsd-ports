# New ports collection makefile for:	uwsgi
# Date created:				23 May 2010
# Whom:					Daniel Gerzo <danger@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	uwsgi
PORTVERSION=	0.9.5.3
CATEGORIES=	www python
MASTER_SITES=	http://projects.unbit.it/downloads/

MAINTAINER=	danger@FreeBSD.org
COMMENT=	Developer-friendly WSGI server which uses uwsgi protocol

MAKE_JOBS_SAFE=	yes

USE_GNOME=	libxml2
USE_PYTHON=	2.4+

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.pre.mk>

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.if ${OSVERSION} < 700000
USE_GCC=	4.2+
BROKEN=		does not build on 6.X
.endif

.include <bsd.port.post.mk>
