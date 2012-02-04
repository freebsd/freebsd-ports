# New ports collection makefile for:	igor
# Date created: 			2012-02-03
# Whom:					gjb@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	igor
PORTVERSION=	1.170
CATEGORIES=	textproc
MASTER_SITES=	http://www.glenbarber.us/ports/${CATEGORIES}/${PORTNAME}/

MAINTAINER=	gjb@FreeBSD.org
COMMENT=	FreeBSD Documentation Project sanity check script

LICENSE=	BSD

USE_PERL5_RUN=	yes

NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.post.mk>
