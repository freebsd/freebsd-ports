# New ports collection makefile for:	postfix-policyd-weight
# Date created:				25 Apr 2005
# Whom:					Robert Felber <robtone@ek-muc.de>
#
# $FreeBSD$
#

PORTNAME=	policyd-weight
PORTVERSION=	0.1.14.17
CATEGORIES=	mail
MASTER_SITES=	http://www.policyd-weight.org/releases/
PKGNAMEPREFIX=	postfix-

MAINTAINER=	robtone@ek-muc.de
COMMENT=	Weighted policy daemon for postfix

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS

SUB_FILES=	pkg-message
PLIST_FILES=	bin/${PORTNAME} etc/${PORTNAME}.conf.sample

USE_RC_SUBR+=	policyd-weight
USE_PERL5=      yes
NO_BUILD=       yes

MAN8+=	policyd-weight.8
MAN5+=	policyd-weight.conf.5

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf.sample ${PREFIX}/etc/
.for i in 5 8
	@${MKDIR} ${PREFIX}/man/man$i
. for j in ${MAN${i}}
	${INSTALL_MAN} ${WRKSRC}/man/man${i}/$j ${PREFIX}/man/man${i}/
. endfor
.endfor

pre-install:
	@${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
