# New ports collection makefile for:	linklint
# Date created:				16 Sep 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	linklint
DISTVERSION=	2.3.6.d
CATEGORIES=	www
MASTER_SITES=	http://www.linklint.org/download/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Perl script that checks links on web sites

USE_PERL5_RUN=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/linklint

post-patch:
	@${REINPLACE_CMD} -e '1s|.*|#!${PERL}|' \
		${WRKSRC}/${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
