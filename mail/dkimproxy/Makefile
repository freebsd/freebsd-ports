# New ports collection makefile for:	dkimproxy
# Date created:				16 July 2006
# Whom:					Yoshisato YANAGISAWA
#
# $FreeBSD$
#

PORTNAME=	dkimproxy
PORTVERSION=	1.1
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	yanagisawa@csg.is.titech.ac.jp
COMMENT=	DKIM filter for Postfix

BUILD_DEPENDS=	${SITE_PERL}/Mail/DKIM.pm:${PORTSDIR}/mail/p5-Mail-DKIM \
		${SITE_PERL}/Net/Server.pm:${PORTSDIR}/net/p5-Net-Server \
		${SITE_PERL}/Error.pm:${PORTSDIR}/lang/p5-Error
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USE_PERL5=	yes
USE_RC_SUBR=	dkimproxy_in dkimproxy_out

DKIMPY_USERNAME?=	dkimproxy
DKIMPY_USERID?=		525
DKIMPY_GROUPNAME?=	${DKIMPY_USERNAME}
DKIMPY_GROUPID?=	${DKIMPY_USERID}

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST=	USER=${DKIMPY_USERNAME} \
		UID=${DKIMPY_USERID} \
		GROUP=${DKIMPY_GROUPNAME} \
		GID=${DKIMPY_GROUPID}

.include <bsd.port.pre.mk>

pre-install:
	${SH} ${PKGINSTALL} ${PREFIX} PRE-INSTALL

.include <bsd.port.post.mk>
