# New ports collection makefile for:	postfix-policyd-weight
# Date created:				25 Apr 2005
# Whom:					Robert Felber <robtone@ek-muc.de>
#
# $FreeBSD$
#

PORTNAME=	policyd-weight
PORTVERSION=	0.1.7
CATEGORIES=	mail
MASTER_SITES=	http://robtone.mine.nu/postfix/releases/
PKGNAMEPREFIX=  postfix-

MAINTAINER=	robtone@ek-muc.de
COMMENT=	Weighted policy daemon for postfix

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS \
		postfix:${PORTSDIR}/mail/postfix-current

SUB_FILES=	pkg-message
PLIST_FILES=	libexec/postfix/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/libexec/postfix

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
