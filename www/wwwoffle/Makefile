# New ports collection makefile for:	wwwoffle
# Date created:		1 Jun 1998
# Whom:			Peter Mutsaers
#
# $FreeBSD$
#

PORTNAME=	wwwoffle
PORTVERSION=	2.8e
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.gedanken.freeserve.co.uk/download-wwwoffle/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=	A caching proxy server for HTTP and FTP designed for dial-up hosts

USE_PERL5=	yes
USE_GMAKE=	yes
USE_RC_SUBR=	yes

# $SPOOL seems like a common name which could be used for other things, so
# use $WWWOFFLE_SPOOL as the overriding setting.
WWWOFFLE_SPOOL?=	/var/spool/wwwoffle

PLIST_SUB+=	WWWOFFLE_SPOOL=${WWWOFFLE_SPOOL}

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS=-lmd
CONFIGURE_ARGS=	--with-confdir=${PREFIX}/etc --with-ipv6 \
		--with-spooldir=${WWWOFFLE_SPOOL}

RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

MAN1=		wwwoffle.1
MAN5=		wwwoffle.conf.5
MAN8=		wwwoffled.8

.if ${WWWOFFLE_SPOOL} != "/var/spool/wwwoffle"
# If using a non-standard spool, change all the documentation (and anything
# else) to reflect that.
PKGMESSAGE=${WRKDIR}/MESSAGE

post-configure:
	@${SED} 's@/var/spool/wwwoffle@${WWWOFFLE_SPOOL}/wwwoffle@g' \
	  ${PKGDIR}/pkg-message > ${PKGMESSAGE}

.endif

post-build:
	@${SED}	${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/wwwoffled.sh > ${WRKDIR}/wwwoffled.sh

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/conf/upgrade-config-2.5-2.6.pl ${WWWOFFLE_SPOOL}
	@${INSTALL_SCRIPT} ${WRKSRC}/conf/upgrade-config-2.x-2.5.pl ${WWWOFFLE_SPOOL}
	@${INSTALL_SCRIPT} ${WRKSRC}/conf/upgrade-config.pl ${WWWOFFLE_SPOOL}
	@${INSTALL_SCRIPT} ${WRKDIR}/wwwoffled.sh ${PREFIX}/etc/rc.d/wwwoffled.sh
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
