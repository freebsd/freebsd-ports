# New ports collection makefile for:	wwwoffle
# Date created:		1 Jun 1998
# Whom:			Peter Mutsaers
#
# $FreeBSD$
#

PORTNAME=	wwwoffle
PORTVERSION=	2.6b
CATEGORIES=	www ipv6
MASTER_SITES=	ftp://ftp.demon.co.uk/pub/unix/httpd/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/www/servers
EXTRACT_SUFX=	.tgz

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014
PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/ \
		ftp://ftp.pasta.cs.uit.no/pub/IPv6/misc/
PATCHFILES=	wwwoffle-26b-v6-20010411.diff.gz
PATCH_DIST_STRIP=	-p1
.endif

MAINTAINER=	sumikawa@FreeBSD.org

USE_PERL5=	yes
USE_GMAKE=	yes

# $SPOOL seems like a common name which could be used for other things, so
# use $WWWOFFLE_SPOOL as the overriding setting.
WWWOFFLE_SPOOL?=	/var/spool
SPOOL=		${WWWOFFLE_SPOOL}

PLIST_SUB+=	SPOOL=${SPOOL}

MAKE_ENV+=	SPOOL="${SPOOL}" \
		BINOWN="${BINOWN}" \
		BINGRP="${BINGRP}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_MAN="${INSTALL_MAN}"

MAN1=		wwwoffle.1
MAN5=		wwwoffle.conf.5
MAN8=		wwwoffled.8

.if ${SPOOL} != "/var/spool"
# If using a non-standard spool, change all the documentation (and anything
# else) to reflect that.
PKGMESSAGE=${WRKDIR}/MESSAGE

do-configure:
	@find ${WRKSRC} | xargs ${CHMOD} u+w
	@find ${WRKSRC} -type f | \
	  xargs perl -pi -e 's@/var/spool/wwwoffle@${SPOOL}/wwwoffle@g'
	@${SED} 's@/var/spool/wwwoffle@${SPOOL}/wwwoffle@g' \
	  ${PKGDIR}/pkg-message > ${PKGMESSAGE}
.endif

post-install:
	@${MKDIR} ${SPOOL}/wwwoffle
	@${INSTALL_SCRIPT} ${WRKSRC}/upgrade-config.pl ${SPOOL}/wwwoffle
	@${SED} 's@%PREFIX%@${LOCALBASE}@' ${FILESDIR}/wwwoffled.sh > ${PREFIX}/etc/rc.d/wwwoffled.sh
	@${CHMOD} +x ${PREFIX}/etc/rc.d/wwwoffled.sh
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
