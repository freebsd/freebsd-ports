# Created by: Fabian Keil <fk@fabiankeil.de>
# $FreeBSD$

PORTNAME=	zogftw
PORTVERSION=	0.0.2013.03.31
CATEGORIES=	sysutils
MASTER_SITES=	http://www.fabiankeil.de/sourcecode/zogftw/
DISTNAME=	${PORTNAME}-2013-03-31-80ef6e9

MAINTAINER=	fk@fabiankeil.de
COMMENT=	Creates redundant backups on encrypted ZFS pools

RUN_DEPENDS=	mbuffer:${PORTSDIR}/misc/mbuffer \
		sudo:${PORTSDIR}/security/sudo

OPTIONS_DEFINE=		GNUPG
OPTIONS_DEFAULT=	GNUPG

PLIST_FILES=	sbin/zogftw

MAN8=		zogftw.8

PORTSCOUT=	ignore:1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUPG}
RUN_DEPENDS+=	gpg:${PORTSDIR}/security/gnupg1 \
		gpg-agent:${PORTSDIR}/security/gnupg
.endif

do-build:
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zogftw ${PREFIX}/sbin/zogftw
	${INSTALL_MAN} ${WRKSRC}/zogftw.8 ${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
