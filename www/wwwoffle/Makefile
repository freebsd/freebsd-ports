# New ports collection makefile for:	wwwoffle
# Date created:		1 Jun 1998
# Whom:			Peter Mutsaers
#
# $FreeBSD$
#

PORTNAME=	wwwoffle
PORTVERSION= 	2.5e
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.demon.co.uk/pub/unix/httpd/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/www/servers
EXTRACT_SUFX=	.tgz

MAINTAINER=	ben@scientia.demon.co.uk

USE_PERL5=	yes

MAN1=		wwwoffle.1
MAN5=		wwwoffle.conf.5
MAN8=		wwwoffled.8

SPOOL=		/var/spool

MAKE_ENV+=	SPOOL="${SPOOL}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_MAN="${INSTALL_MAN}"

post-install:
	@${MKDIR} ${SPOOL}/wwwoffle
	@${INSTALL_SCRIPT} ${WRKSRC}/upgrade-config.pl ${SPOOL}/wwwoffle
	@${INSTALL_SCRIPT} ${FILESDIR}/wwwoffled.sh ${PREFIX}/etc/rc.d
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
