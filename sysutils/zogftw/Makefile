# Created by: Fabian Keil <fk@fabiankeil.de>
# $FreeBSD$

PORTNAME=	zogftw
PORTVERSION=	0.0.2013.10.06
CATEGORIES=	sysutils
MASTER_SITES=	http://www.fabiankeil.de/sourcecode/zogftw/
DISTNAME=	${PORTNAME}-2013-10-06-4760e2c

MAINTAINER=	fk@fabiankeil.de
COMMENT=	Creates redundant backups on encrypted ZFS pools

RUN_DEPENDS=	mbuffer:${PORTSDIR}/misc/mbuffer \
		sudo:${PORTSDIR}/security/sudo

OPTIONS_DEFINE=		GNUPG
OPTIONS_DEFAULT=	GNUPG

PLIST_FILES=	sbin/zogftw \
		man/man8/zogftw.8.gz

NO_BUILD=	yes
PORTSCOUT=	ignore:1

GNUPG_RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg1 \
			gpg-agent:${PORTSDIR}/security/gnupg

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zogftw ${STAGEDIR}${PREFIX}/sbin/zogftw
	${INSTALL_MAN} ${WRKSRC}/zogftw.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
