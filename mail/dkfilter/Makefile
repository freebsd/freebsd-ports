# New ports collection makefile for:	dkfilter
# Date created:				3 Nov 2005
# Whom:					Yoshisato YANAGISAWA
#
# $FreeBSD$
#

PORTNAME=	dkfilter
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://jason.long.name/dkfilter/

MAINTAINER=	yanagisawa@csg.is.titech.ac.jp
COMMENT=	Domainkeys filter for Postfix

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Crypt/OpenSSL/RSA.pm:${PORTSDIR}/security/p5-Crypt-OpenSSL-RSA \
		${SITE_PERL}/Mail/Address.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/Net/Server.pm:${PORTSDIR}/net/p5-Net-Server
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USE_PERL5=	yes
USE_RC_SUBR=	dkfilter_in dkfilter_out

DKFILTER_USERNAME?=	dkfilter
DKFILTER_USERID?=	325
DKFILTER_GROUPNAME?=	${DKFILTER_USERNAME}
DKFILTER_GROUPID?=	${DKFILTER_USERID}

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST=	USER=${DKFILTER_USERNAME} \
		UID=${DKFILTER_USERID} \
		GROUP=${DKFILTER_GROUPNAME} \
		GID=${DKFILTER_GROUPID}

pre-install:
	${SH} ${PKGINSTALL} ${PREFIX} PRE-INSTALL

.include <bsd.port.mk>
