# New ports collection makefile for:	rkhunter
# Date created:		15 May 2004
# Whom:			Radim Kolar
#
# $FreeBSD$
#

PORTNAME=	rkhunter
PORTVERSION=	1.0.8
CATEGORIES=	security
MASTER_SITES=	http://downloads.rootkit.nl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rootkit detection tool

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_PERL5=	yes
NO_BUILD=	yes
USE_REINPLACE=	yes

PLIST_DIRS=	rkhunter/scripts rkhunter/db rkhunter/docs rkhunter/tmp rkhunter
PLIST_FILES=	rkhunter/scripts/check_modules.pl \
		rkhunter/scripts/check_port.pl \
		rkhunter/scripts/filehashmd5.pl \
		rkhunter/scripts/filehashsha1.pl \
		bin/rkhunter \
		etc/rkhunter.conf \
		rkhunter/scripts/showfiles.pl \
		rkhunter/db/backdoorports.dat \
		rkhunter/db/mirrors.dat \
		rkhunter/db/os.dat \
		rkhunter/db/defaulthashes.dat \
		rkhunter/db/md5blacklist.dat \
		rkhunter/docs/CHANGELOG \
		rkhunter/docs/README \
		rkhunter/docs/WISHLIST

MAN8=		rkhunter.8
MANCOMPRESSED=	no

pre-install:
		${REINPLACE_CMD} -e "s,/usr/local,${PREFIX},g" ${WRKSRC}/installer.sh
do-install:
		cd ${WRKSRC} && ./installer.sh
		${INSTALL_MAN} ${WRKSRC}/files/development/rkhunter.8 ${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
