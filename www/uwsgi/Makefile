# New ports collection makefile for:	uwsgi
# Date created:				23 May 2010
# Whom:					Daniel Gerzo <danger@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	uwsgi
PORTVERSION=	0.9.6.8
CATEGORIES=	www python
MASTER_SITES=	http://projects.unbit.it/downloads/

MAINTAINER=	danger@FreeBSD.org
COMMENT=	Developer-friendly WSGI server which uses uwsgi protocol

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

MAKE_JOBS_SAFE=	yes

USE_GNOME=	libxml2
USE_PYTHON=	yes
USE_RC_SUBR=	uwsgi

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.pre.mk>

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.if ${OSVERSION} < 700000
BROKEN=		does not build on 6.X
.endif

.include <bsd.port.post.mk>
