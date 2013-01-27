# Created by: Antonio Querubin <tony@lava.net>
# $FreeBSD$

PORTNAME=	rcsedit
PORTVERSION=	1.3.2
CATEGORIES=	sysutils
MASTER_SITES=	http://malasada.lava.net/rcsedit/ \
		http://lava.net/files/rcsedit/ \
		http://ipv6.lava.net/rcsedit/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple wrapper for RCS written in Perl

DEPRECATED=	No more upstream, no more public distfiles
EXPIRATION_DATE=	2013-02-27

PLIST_FILES=	bin/rcsedit

USE_PERL5_RUN=	yes

post-patch:
	@${REINPLACE_CMD} -e '1s|.*perl|#!${PERL}|' ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
